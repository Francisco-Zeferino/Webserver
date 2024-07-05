/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:56:39 by ffilipe-          #+#    #+#             */
/*   Updated: 2024/07/05 11:34:08 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

class Server{
    private:
        int serverSocket;
        int newSocket;
        long readValue;
        int addrLen; 
        struct sockaddr_in address;
        void bindSocket();
        void establishConnection();
    public :
        Server();
        
};

#endif