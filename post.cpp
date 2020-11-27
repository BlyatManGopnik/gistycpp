#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
using std::basic_string, std::string, std::cout, std::endl;
namespace post {
    basic_string<char> post(basic_string<char> authtoken, basic_string<char> content) {
        string jsondata = "{\"files\": {\"gistycpp.txt\": {\"content\": \""+content+"\"}}}";
        cpr::Response r = cpr::Post(cpr::Url{"https://api.github.com/gists"},
                                    cpr::Header{{"User-Agent", "gistycpp"},
                                                {"Authorization", "token " + authtoken},
                                                {"Content-Type", "application/json"}},
                                                cpr::Body{jsondata});
        nlohmann::json parse = nlohmann::json::parse(r.text);
        try {
            string error = parse["message"];
            cout << "Error: " + error << endl;
            cout << jsondata << endl;
            exit(1);
        } catch(nlohmann::detail::type_error) {}
        return parse["html_url"];
    }
}