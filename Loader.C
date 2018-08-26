

#include<iostream>
#include<string>
#include<string.h>
#include<dlfcn.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

#include "./plugin/PluginInterface.h"

using namespace std;

Task *taskObj=NULL;

void *thread_callback(void *handle)
{

 // Download and reporting status message

 
//  taskObj->run();
  return NULL;

}


int main(int argc, char **argv)
{

   char pluginName[25];
   pthread_t threadid;
   Task *taskObj=NULL;
  
   if(argc < 2) {
       cout << " Please input the plugin "<<endl; 
       return -1; 
   } 

   strcpy(pluginName,argv[1]);


   // Here I have to handle loading of plugins as when it is copied to a directory.
   // I think we have to use inotify standard library to handle the file notification which is pending.
 
   void *handle;
    
   handle = dlopen("./plugin/speed_test_curl.so", RTLD_NOW);

   if (!handle)
   {
      cout<<"Unable to load the plugin"<<dlerror();
   }
   else {

      cout<<"Plugin Name : "<< pluginName<<endl;
   }
    
    typedef Task* create_t();
    typedef void destroy_t(Task*);
 
    create_t* creat = (create_t*) dlsym(handle,"create");
    destroy_t* destroy = (destroy_t*) dlsym(handle,"destroy");
    if (!creat)
    {
           cout<<"%s"<<dlerror();
    }
    if (!destroy)
    {
           cout<<"%s"<<dlerror();
    }

    // I am spawning a thread for Downloading and reporting status message. 
    
    taskObj = creat();
    
    if(pthread_create(&threadid, NULL, thread_callback, handle)) {

	cout<< "Error creating thread\n"<<endl;
	return 1;
    }    

    taskObj->run();
    cout<<pluginName<<":";
    taskObj->get_status_msg();
    destroy(taskObj);
   
   return 0;
}
