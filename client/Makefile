CFLAGS = -g -Wall
OPTIONS = -lprotobuf-c -lpthread 

client: 
	gcc $(CFLAGS) client.c msg.pb-c.c input_processing.c message_processing.c -o client $(OPTIONS)

clean:
	rm client

