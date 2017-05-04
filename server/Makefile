CFLAGS= -g -Wall

all: server relauncher readstdin 


server: 
	gcc $(CFLAGS) server.c msg.pb-c.c chat_storage.c log_system.c message_handler.c user_management.c -o server -lprotobuf-c -lpthread -lrt

relauncher:
	gcc $(CFLAGS) relauncher.c log_system.c -o relauncher -lpthread -lrt

readstdin:
	gcc $(CFLAGS) readstdin.c log_system.c -o readstdin -lrt

clean:
	rm server relauncher readstdin
