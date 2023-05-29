const CGI_URL = 'https://cors-anywhere.herokuapp.com/http://uvuv643.ru/cgi-bin/main'
const WIDTH = 420;
const HEIGHT = 420;

const solutions = ['sqrt((log(x))^2 - 1)', '2 - cos(x)', '-1.257013 / x^2', '-cos(x)']

$(document).ready(function () {

    MathJax = {
        tex: {inlineMath: [['$', '$'], ['\\(', '\\)']]}
    };

    let chosenFunction = 0

    $('.function__item').on('click', function (event) {
        event.preventDefault()
        chosenFunction = parseInt($(this).attr('data-function'))
        $(this).addClass('_active')
        setTimeout(() => {
            $('.page-content').addClass('_hidden')
            $('.solution-equation').html($(this).html())
            setTimeout(() => {
                $('.page-solution').removeClass('_hidden')
            }, 500)
        }, 500)
    })

    $('.solution__back').on('click', function (event) {
        event.preventDefault()
        $('.page-solution').addClass('_hidden')
        setTimeout(() => {
            $('.page-content').removeClass('_hidden')
        }, 500)
    })

    $('.main-form').on('submit', function (event) {
        event.preventDefault();

        (() => {

            try {

                let elements = {
                    x_0: $('input[name="x_0"]'),
                    y_0: $('input[name="y_0"]'),
                    x_n: $('input[name="x_n"]'),
                    h: $('input[name="h"]'),
                    eps: $('input[name="eps"]'),
                }

                let canBeSubmitted = true;
                for (const element of Object.values(elements)) {
                    element.val(element.val().replace(',', '.'))
                    let targetValue = element.val()
                    if (!targetValue || isNaN(parseFloat(targetValue))) {
                        element.addClass('_error')
                        canBeSubmitted = false
                    }
                }

                if (canBeSubmitted) {
                    if (parseFloat(elements.eps.val()) > 0) {
                        let x_0 = parseFloat(elements.x_0.val())
                        let x_n = parseFloat(elements.x_n.val())
                        let h = parseFloat(elements.h.val())
                        let y_0 = parseFloat(elements.y_0.val())
                        let eps = parseFloat(elements.eps.val())
                        let steps = (x_n - x_0) / h
                        if (steps > 1 && steps < 100) {

                            for (let i = 0; i < steps; i++) {
                                $('tbody').append(' <tr class="table-m' + (i) + '">' +
                                    '                            <td>' + (x_0 + i * h).toFixed(4) + '</td>' +
                                    '                        </tr>')
                            }

                            $('.page-solution').addClass('_hidden')

                            let methodPromises = []
                            for (let method of ['euler', 'euler_modified', 'adams']) {
                                let currentPromise = fetch(CGI_URL, {
                                    method: 'POST',
                                    body: JSON.stringify({
                                        "x_0": x_0,
                                        "y_0": y_0,
                                        "x_n": x_n,
                                        "h": h,
                                        "eps": eps,
                                        "function_number": chosenFunction,
                                        "method": method
                                    })
                                }).then(response => response.json())
                                methodPromises.push(currentPromise)
                            }

                            Promise.all(methodPromises)
                                .then(response => {
                                    const eulerResult = response[0]
                                    const eulerModifiedResult = response[1]
                                    const adamsResult = response[2]

                                    $('.actual_h1').html(eulerResult.h_actual.toFixed(5))
                                    $('.actual_h2').html(eulerModifiedResult.h_actual.toFixed(5))
                                    $('.actual_h3').html(adamsResult.h_actual.toFixed(5))

                                    let targetPointsEuler = []
                                    let targetPointsEulerModified = []
                                    let targetPointsAdams = []

                                    steps = Math.min(steps, eulerResult.result.length)
                                    steps = Math.min(steps, eulerModifiedResult.result.length)
                                    steps = Math.min(steps, adamsResult.result.length)

                                    for (let i = 0; i < steps; i++) {
                                        targetPointsEuler.push([(x_0 + i * h).toFixed(4), eulerResult.result[i]])
                                        targetPointsEulerModified.push([(x_0 + i * h).toFixed(4), eulerModifiedResult.result[i]])
                                        targetPointsAdams.push([(x_0 + i * h).toFixed(4), adamsResult.result[i]])

                                        try {
                                            $('.table-m' + i).append('<td>' + eulerResult.result[i].toFixed(4) + '</td>')
                                            $('.table-m' + i).append('<td>' + eulerModifiedResult.result[i].toFixed(4) + '</td>')
                                            $('.table-m' + i).append('<td>' + adamsResult.result[i].toFixed(4) + '</td>')
                                        } catch (error) {
                                            $('.page-answer').html('<div class="centered">Unable to solve this</div>')
                                        }

                                    }

                                    console.log(targetPointsAdams, targetPointsEuler, targetPointsEulerModified)

                                    functionPlot({
                                        target: '#root',
                                        width: WIDTH,
                                        height: HEIGHT,
                                        xAxis: {
                                            label: 'blue - euler default; red - euler modified; green - adams',
                                            domain: [-6, 6]
                                        },
                                        data: [{
                                            points: targetPointsEuler,
                                            fnType: 'points',
                                            graphType: 'scatter'
                                        }, {
                                            points: targetPointsEulerModified,
                                            fnType: 'points',
                                            graphType: 'scatter'
                                        }, {
                                            points: targetPointsAdams,
                                            fnType: 'points',
                                            graphType: 'scatter'
                                        }, {
                                            fn: solutions[chosenFunction]
                                        }]
                                    })

                                    $('main').addClass('_active')
                                    $('.page-answer').removeClass('_hidden')
                                })

                        } else {
                            elements.h.addClass('_error')
                        }
                    } else {
                        elements.eps.addClass('_error')
                    }
                }

            } catch (error) {
                $('.page-answer').html('<div class="centered">Unable to solve this</div>')
            }

        })()
    })


    $('input').on('input', function () {
        $(this).removeClass('_error')
    })

    $('.answer__back').on('click', function () {
        console.log('Answer back clicked')
        window.location.reload()
    })

})