
#include<iostream>

using namespace std;


class Task 
{
public:
 	virtual ~Task(){}
	virtual bool run() = 0;
	virtual int get_progress() = 0;
	virtual std::string get_status_msg() = 0;
};
