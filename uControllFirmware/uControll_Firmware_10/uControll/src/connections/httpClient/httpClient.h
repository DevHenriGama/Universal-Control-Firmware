#ifndef HttpClient_h
#define HttpClient_h

#include <HTTPClient.h>
#include <string>

using namespace std;

class HttpClient {
    private:
        HTTPClient client;
    public:
        HttpClient();
        String GET(String url);
        String POST(String url, String body,int expectedCode);

};





#endif