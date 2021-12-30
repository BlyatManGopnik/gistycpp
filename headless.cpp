#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include "sleep.hpp"
using std::cout, std::endl, std::string, std::basic_string;
namespace headless {
    bool authtokendone;
    string access;
    int trys;
	basic_string<char> getdevicecode(const char clientid[]) {
	    authtokendone = false;
		cout << "Starting headless GitHub authentication" << endl;
		cpr::Response r = cpr::Post(cpr::Url{"https://github.com/login/device/code"},
		        cpr::Parameters{{"client_id", clientid}, {"scope", "gist"}},
		        cpr::Header{{"Accept", "application/json"}, {"User-Agent", "gistycpp"}});
		nlohmann::json parse = nlohmann::json::parse(r.text);
		string usercode = parse["user_code"];
		cout << "I got a code you should enter at https://github.com/login/device"
		<< endl << "Code: " + usercode << endl;
		return parse["device_code"];
	}
	basic_string<char> getauthtoken(basic_string<char> devicecode, basic_string<char> clientid) {
	    trys = 0;
	    while (authtokendone == false) {
	        try {
	            trys = trys + 1;
	            const char * client = clientid.c_str();
	            const char * device = devicecode.c_str();
                cpr::Response response = cpr::Post(cpr::Url{"https://github.com/login/oauth/access_token"},
                                            cpr::Header{{"Accept", "application/json"}, {"User-Agent", "gistycpp"}},
                                            cpr::Parameters{{"client_id", client},
                                                            {"device_code", device},
                                                            {"grant_type", "urn:ietf:params:oauth:grant-type:device_code"}});
                nlohmann::json tokenjson = nlohmann::json::parse(response.text);
                access = tokenjson["access_token"];
                authtokendone = true;
	        } catch (nlohmann::detail::type_error e){
                sleep_seconds(5);
	        }
	    }
        return access;
	}
}
