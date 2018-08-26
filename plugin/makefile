CC=g++
CFLAGS=-I.

speed_test_curl: TestSpeed.o
	$(CC) -shared -fPIC TestSpeed.C -o speed_test_curl.so -lcurl

