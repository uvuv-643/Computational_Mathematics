//
// Created by artem on 27.02.2023.
//

#include "GraphicManager.h"

void GraphicManager::drawSingleX(FILE* gnu_pipe, CFunctionSV *function, double a, double b) {
    fprintf(gnu_pipe, "set key left box \n");
    fprintf(gnu_pipe, "set samples 200 \n");
    string function_definition = (function->function_definition);
    size_t pos;
    while ((pos = function_definition.find('^')) != std::string::npos) {
        function_definition.replace(pos, 1, "**");
    }
    string plot_text = "plot [" + to_string(ceil(a - 1)) + ":" + to_string(floor(b + 1)) + "] " + function_definition + " \n";
    fprintf(gnu_pipe, plot_text.c_str());
    fflush(gnu_pipe);
}

void GraphicManager::drawSingleX(FILE *gnu_pipe, string function_definition, double a, double b) {
    fprintf(gnu_pipe, "set key left box \n");
    fprintf(gnu_pipe, "set samples 200 \n");
    fprintf(gnu_pipe, "set size ratio 1 \n");
    fprintf(gnu_pipe, "set xzeroaxis lt -1 lw 1 \n");
    fprintf(gnu_pipe, "set yzeroaxis lt -1 lw 1 \n");
    string range_x_definition = "set xrange [" + to_string(ceil(a - 1)) + ":" + to_string(floor(b + 1)) + "] \n";
    string range_y_definition = "set yrange [" + to_string(- (b - a + 2) / 2) + ":" + to_string((b - a + 2) / 2) + "] \n";
    fprintf(gnu_pipe, range_x_definition.c_str());
    fprintf(gnu_pipe, range_y_definition.c_str());
    fprintf(gnu_pipe, "set samples 200 \n");
    size_t pos;
    while ((pos = function_definition.find('^')) != std::string::npos) {
        function_definition.replace(pos, 1, "**");
    }
    string plot_text = "plot  " + function_definition + "\n";
    fprintf(gnu_pipe, plot_text.c_str());
    fflush(gnu_pipe);
}

void GraphicManager::drawMultipleX(FILE *gnu_pipe, CFunctionSV *function, double a, double b) {
    fprintf(gnu_pipe, "set key left box \n");
    fprintf(gnu_pipe, "set samples 200 \n");
    string function_definition = (function->function_definition_phi);
    size_t pos;
    while ((pos = function_definition.find('^')) != std::string::npos) {
        function_definition.replace(pos, 1, "**");
    }
    string plot_text = "plot [" + to_string(ceil(a - 1)) + ":" + to_string(floor(b + 1)) + "] " + function_definition + ", x \n";
    fprintf(gnu_pipe, plot_text.c_str());
    fflush(gnu_pipe);
}

void GraphicManager::drawSingleXY(FILE* gnu_pipe, CFunctionMV *function) {
    fprintf(gnu_pipe, "set contour \n");
    fprintf(gnu_pipe, "set view map \n");
    fprintf(gnu_pipe, "set cont base \n");
    fprintf(gnu_pipe, "set cntrparam levels discrete 0,0 \n");
    fprintf(gnu_pipe, "unset surface \n");
    fprintf(gnu_pipe, "set surface \n");
    string function_definition = (function->function_definition);
    size_t pos;
    while ((pos = function_definition.find('^')) != std::string::npos) {
        function_definition.replace(pos, 1, "**");
    }
    string plot_text = "splot " + function_definition + " \n";
    fprintf(gnu_pipe, plot_text.c_str());
    fflush(gnu_pipe);
}


void GraphicManager::drawMultipleXY(FILE* gnu_pipe, CFunctionMV *f, CFunctionMV *g) {
    fprintf(gnu_pipe, "set contour \n");
    fprintf(gnu_pipe, "set view map \n");
    fprintf(gnu_pipe, "set cont base \n");
    fprintf(gnu_pipe, "set cntrparam levels discrete 0,0 \n");
    fprintf(gnu_pipe, "unset surface \n");
    fprintf(gnu_pipe, "set surface \n");
    string function1_definition = (f->function_definition);
    size_t pos;
    while ((pos = function1_definition.find('^')) != std::string::npos) {
        function1_definition.replace(pos, 1, "**");
    }
    string function2_definition = (g->function_definition);
    while ((pos = function2_definition.find('^')) != std::string::npos) {
        function2_definition.replace(pos, 1, "**");
    }
    string plot_text = "splot " + function1_definition + ", " + function2_definition + "\n";
    fprintf(gnu_pipe, plot_text.c_str());
    fflush(gnu_pipe);
}

void GraphicManager::drawSingleXWithPoints(FILE *gnu_pipe, string function_definition, vector<CDouble>& x, vector<CDouble>& y, double a,
                                           double b) {

    fprintf(gnu_pipe, "set key left box \n");
    fprintf(gnu_pipe, "set key left box \n");
    fprintf(gnu_pipe, "set samples 200 \n");
    fprintf(gnu_pipe, "set size ratio 1 \n");
    fprintf(gnu_pipe, "set xzeroaxis lt -1 lw 1 \n");
    fprintf(gnu_pipe, "set yzeroaxis lt -1 lw 1 \n");
    string range_x_definition = "set xrange [" + to_string(ceil(a - 5)) + ":" + to_string(floor(b + 5)) + "] \n";
    string range_y_definition = "set yrange [" + to_string(- (b - a + 2) / 2) + ":" + to_string((b - a + 2) / 2) + "] \n";
    fprintf(gnu_pipe, range_x_definition.c_str());
    fprintf(gnu_pipe, range_y_definition.c_str());
    size_t pos;
    while ((pos = function_definition.find('^')) != std::string::npos) {
        function_definition.replace(pos, 1, "**");
    }
    string plot_text = "plot  " + function_definition + " with lines linecolor rgb '#8b1a0e', ";

    std::ostringstream ss;
    ss << "set style line 1 pointtype 7 pointsize 1.5 lc rgb \"#8070D8\"\n" << endl;
    ss << plot_text;
    ss << "'-' with points ls 1 title \"Points\"\n";
    for (int i = 0; i < x.size(); i++) {
        ss << x[i] << " " << y[i] << "\n";
    }
    ss << "e\n";

    fprintf(gnu_pipe, ss.str().c_str());
    fflush(gnu_pipe);

}


