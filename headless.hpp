using std::basic_string;
namespace headless {
	basic_string<char> getdevicecode(const char string[1]);
    basic_string<char> getauthtoken(basic_string<char> devicecode, basic_string<char> clientid);
}
namespace post {
    basic_string<char> post(basic_string<char> authtoken, basic_string<char> content);
}