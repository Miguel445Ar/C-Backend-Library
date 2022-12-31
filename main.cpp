#include <iostream>
#include "networking/HTTP_Server.hpp"
#include "json-conversion/JSON_builder.hpp"

int main() {
    HTTPServer server(5000);
    server.run();
    return 0;
}