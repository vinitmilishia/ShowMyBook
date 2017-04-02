/*
    C socket server, handles multiple clients using threads
*/

#include<stdio.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread
#include <sys/time.h> //for date and time in log file

//the thread function
void *connection_handler(void *);

int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , *new_sock;
    struct sockaddr_in server , client;
    FILE *log;

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket"); //if any error in creating socket
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;

        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        //puts("Handler assigned to client");
        time_t ltime; /* calendar time */
        ltime=time(NULL); /* get current cal time */

        log=fopen("smb.log", "a");
          if (log == NULL)
          {
                   printf("Error opening file!\n");
                   exit(1);
          }
          fprintf(log, "Client connected from: %s at %s\n", inet_ntoa(client.sin_addr),asctime(localtime(&ltime)));

        printf("Handler assigned to client from: %s\n", inet_ntoa(client.sin_addr));
        fclose(log);
    }
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }

    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    int sid,i;
    char *message , client_message[2000];
    char subjectName[8][50]={"1. Advanced Computing Concepts","2. Marketing Management","3. System Programming","4. Internet Application & Distributed System","5. Advanced Database Concepts","6. Network & Security System","7. Managing Employees","8. Software Engineering"};
    char acc[3][5000]={"Advanced Computing Concepts Book 1","Advanced Computing Concepts Book 2","Advanced Computing Concepts Book 3"};
    char mm[3][5000]={"1. Marketing Management (14th Edition) Hardcover – Feb 8 2011 by Philip T. Kotler","2. Marketing Management by Peter, Donnelly","3. Principles of Marketing (16th Edition)"};
    char sp[3][5000]={"1. Advanced Programming in the Unix environment. W. Richard Stevens and Stephen A. Rago. Addison Wesley, 3rd Ed","2. System Programming with C and Unix Paperback – Feb 13 2009 by Adam Hoover","3. Advanced UNIX Programming: Edition 2 , 29 April 2004 ,Pearson Education by Marc J. Rochkind"};
    char iads[3][5000]={"Internet Application & DS Book 1","Internet Application & DS Book 2","Internet Application & DS Book 3"};
    char adc[3][5000]={"1. Database Systems: Design, Implementation, and Management, 11th Edition, by C. Coronel and S. Morris, Cengage Learning, 2014","2. Database Systems: A Practical Approach to Design, Implementation, and Management, 6th Edition by Thomas Connolly, Carolyn Begg, Pearson, 2014","3. NoSQL Distilled: A Brief Guide to the Emerging World of Polyglot Persistence, by P. J. Sadalage and M. Fowler, Addison-Wesley Professional, 2012"};
    char nss[3][5000]={"Network & Security Book 1","Network & Security Book 2","Network & Security Book 3"};
    char me[3][5000]={"1. Johns, G. & Saks, A. (2017). Organizational Behaviour: Understanding & Managing Life at Work (10th ed.)","2. Managing Employee Performance: An Accelerated Learning Text for Supervisors and Students Paperback – September 18, 2009","3. Managing Employment Relations Paperback – September 1, 2010 by John Gennard"};
    char se[3][5000]={"Software Engineering Book 1","Software Engineering Book 2","Software Engineering Book 3"};

    //Send some messages to the client
    write(sock, "Connected Successfully \n", strlen("Connected Successfully \n"));
    x:for(i=0;i<=8;i++)
    {
        write(sock , subjectName[i] , strlen(subjectName[i]));
        write(sock , "\n" , strlen("\n"));
    }

    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        puts(client_message);
        //Send the message back to client
        if(*client_message=='$'){
            read_size=0;
            break;
        }
        if(*client_message=='#'){
          goto x;
        }
          sid=atoi(client_message);
        switch (sid) {
            case 1:for(i=1;i<=5;i++)
                    {
                      write(sock , acc[i] , strlen(acc[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;

            case 2:for(i=1;i<=5;i++)
                    {
                        write(sock , mm[i] , strlen(mm[i]));
                        write(sock , "\n" , strlen("\n"));
                    }
                    break;

            case 3:for(i=1;i<=5;i++)
                    {
                      write(sock , sp[i] , strlen(sp[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;

            case 4:for(i=1;i<=5;i++)
                    {
                      write(sock , iads[i] , strlen(iads[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;

            case 5:for(i=0;i<=5;i++)
                    {
                      write(sock , adc[i] , strlen(adc[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;

            case 6:for(i=1;i<=5;i++)
                    {
                      write(sock , nss[i] , strlen(nss[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;
            case 7:for(i=1;i<=5;i++)
                    {
                      write(sock , me[i] , strlen(me[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;
            case 8:for(i=1;i<=5;i++)
                    {
                      write(sock , se[i] , strlen(se[i]));
                      write(sock , "\n" , strlen("\n"));
                    }
                    break;
          default:write(sock,"Invalid Id",strlen("Invalid Id"));

        }

    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    //Free the socket pointer
    free(socket_desc);

    return 0;

}
