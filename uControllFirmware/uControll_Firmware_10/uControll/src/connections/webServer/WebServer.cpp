#include "./WebServer.h"
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

WebServer::WebServer(){};

void WebServer::Routes(){
 server.on("/",HTTP_GET,[](AsyncWebServerRequest* request){
    request->send(200,"text/html","Olá");
 });

};

void WebServer::Start(){
    if(WiFi.status() != WL_CONNECTED){
        return;
    };

    Routes();

    server.begin();
};

