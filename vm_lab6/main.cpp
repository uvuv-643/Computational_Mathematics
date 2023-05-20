//
// Created by K49-R355-M11 on 20.05.2023.
//

#include "methods/EulerMethod.h"
#include "methods/EulerModified.h"
#include "methods/AdamsMethod.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    nlohmann::json request(nlohmann::json::parse(std::cin));
    double x_0 = request["x_0"];
    double y_0 = request["y_0"];
    double x_n = request["x_n"];
    double h = request["h"];
    double eps = request["eps"];
    int32_t function = request["function_number"];
    string method = request["method"];

    nlohmann::json response;
    if (method == "euler") {
        EulerMethod method(x_0, x_n, y_0, h, eps);
        pair<double, vector<double>> answer = method.perform_method(manager.get_function(function));
        response["h_actual"] = answer.first;
        response["result"] = answer.second;
    } else if (method == "euler_modified") {
        EulerModified method(x_0, x_n, y_0, h, eps);
        pair<double, vector<double>> answer = method.perform_method(manager.get_function(function));
        response["h_actual"] = answer.first;
        response["result"] = answer.second;
    } else if (method == "adams") {
        AdamsMethod method(x_0, x_n, y_0, h, eps);
        pair<double, vector<double>> answer = method.perform_method(manager.get_function(function));
        response["h_actual"] = answer.first;
        response["result"] = answer.second;
    }

    std::cout << "Content-type: application/json" << std::endl << std::endl;
    std::cout << response.dump(2) << std::endl;
    return 0;

}


//int main() {
//
//    CDifferentialFunctionManager manager;
//
//    AdamsMethod method(-1.7, 4.5, 1.132, 0.1, 0.1);
//
//    pair<double, vector<double>> data = method.perform_method(manager.get_function(3));
//    vector<double> answer = data.second;
//
//    cout << data.first << endl;
//    for (int i = 0; i < answer.size(); i++) {
//        cout << answer[i] << " ";
//    }
//    cout << endl;
//
//    return 1;
//
//}