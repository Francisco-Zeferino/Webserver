/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:55:01 by ffilipe-          #+#    #+#             */
/*   Updated: 2024/07/05 11:48:33 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(){
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    memset(address.sin_zero, '\0', sizeof(address.sin_zero));
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "In socket" << std::endl;
        _exit(0);
    }
    bindSocket();
    establishConnection();
}

void Server::bindSocket(){
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        std::cerr << "In bind" << std::endl;
        _exit(0);
    }
    if (listen(serverSocket, 10) < 0)
    {
        std::cerr << "In listen" << std::endl;
        _exit(0);
    }
}

void Server::establishConnection(){
    std::string hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    while(1){
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrLen))<0)
        {
            perror("In accept");
            _exit(0);
        }
        
        char buffer[30000] = {0};
        readValue = read( newSocket , buffer, 30000);
        printf("%s\n",buffer );
        write(newSocket , hello.c_str() , strlen(hello.c_str()));
        printf("------------------Hello message sent-------------------\n");
        close(newSocket);
    }
}

int main(){
    Server serverclass;
}