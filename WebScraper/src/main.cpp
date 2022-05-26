#include <cpr/cpr.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <Document.h>
#include <Node.h>
#include <vector>
#include <fstream>


int main() {

    cpr::Response r = cpr::Get(cpr::Url{ "https://testsheepnz.github.io/BasicCalculator.html" });
    r.status_code;                  // 200
    r.header["content-type"];       // application/json; charset=utf-8
    //fmt::print("{}",r.text);                         // JSON text string
    CDocument page;
    page.parse(r.text.c_str());
    fmt::print("{} \n", r.text);
    /*CSelection selector = page.find("body");
    fmt::print("{}", selector.nodeAt(0).text());*/

	return EXIT_SUCCESS;
}