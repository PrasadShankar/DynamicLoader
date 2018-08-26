
#include "PluginInterface.h"

#include<curl/curl.h>
#include<iostream>
#include<string>

class CurlPlugin : public Task 
{
 public:

     CurlPlugin();
     bool run();
     int get_progress(); 
     std::string get_status_msg(); 

 private:
     FILE *fp;
     CURL *m_curl;
     char outfilename[255];
};
 

