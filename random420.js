const compiler = require("compilex");
compiler.init({ stats: true });

const envData = { OS: "windows", cmd: "g++", options: { timeout: 1000 } };

const code = `#include<iostream>
using namespace std;
int main() {
    cout << "Hello from C++";
    return 0;
}`;

compiler.compileCPP(envData, code, function (data) {
  console.log(data.output);
});
