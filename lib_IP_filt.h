#pragma once

#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

//Create specific type
using IP_vv = std::vector<std::vector<std::string> >;
using IP_v = std::vector<std::string>;

//Test function
void Hello();

//Forward sort IP adress vector
void sort_IP(IP_vv& IP_address);

//Reverse sort IP adress vector
void r_sort_IP(IP_vv& IP_address);

//Find matching specific IP - order important 
IP_vv IP_filter_sp(IP_vv & IP_address,IP_v Compar_IP);

//Find matching any IP - order unimportant
IP_vv IP_filter_any(IP_vv & IP_address, IP_v Compar_IP);


