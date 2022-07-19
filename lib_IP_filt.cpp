#include "lib_IP_filt.h"

//Test function
void Hello()
{
	std::cout<<"ddad";
}

//Forward sort IP adress vector
void sort_IP(IP_vv& IP_address)
{
	std::sort(IP_address.begin(), IP_address.end(), [](IP_v l_IP,IP_v r_IP)
	{
		for (unsigned int i = 0; i < l_IP.size(); i++)
		{
			if (std::stoi(l_IP.at(i)) < std::stoi(r_IP.at(i))) return true;
			if (std::stoi(l_IP.at(i)) > std::stoi(r_IP.at(i))) return false;
		}
		return false;
	});
}

//Reverse sort IP adress vector
void r_sort_IP(IP_vv& IP_address)
{
	std::sort(IP_address.begin(), IP_address.end(), [](IP_v l_IP, IP_v r_IP)
	{
		for (unsigned int i = 0; i < l_IP.size(); i++)
		{
			if (std::stoi(l_IP.at(i)) > std::stoi(r_IP.at(i))) return true;
			if (std::stoi(l_IP.at(i)) < std::stoi(r_IP.at(i))) return false;
		}
		return false;
	});
}

//Find matching specific IP - order important 
IP_vv IP_filter_sp(IP_vv & IP_address, IP_v Comparative_IP)
{
	IP_vv temp;

	for (auto ip = IP_address.cbegin(); ip != IP_address.cend(); ++ip)
	{

		unsigned int i = 0;
		// Compare number bcs faster
		while ((i < Comparative_IP.size()) && (std::stoi(ip->at(i)) == std::stoi(Comparative_IP.at(i))) )
		{
			i++;
		}
		if (i == Comparative_IP.size())	temp.emplace_back(*ip);

	}

	return (temp);

}

//Find matching any IP - order unimportant
IP_vv IP_filter_any(IP_vv & IP_address, IP_v Comparative_IP)
{
	IP_vv temp;

	for (auto ip = IP_address.cbegin(); ip != IP_address.cend(); ++ip)
	{

		unsigned int i = 0;
		unsigned int j = 0;

		while (i < ip->size() && (j < Comparative_IP.size()))
		{

			while ((j < Comparative_IP.size()) && (i + j < ip->size())&& (std::stoi(ip->at(i+j)) == std::stoi(Comparative_IP.at(j))))
			{

				j++;

			}

			i++;
			if ((j == Comparative_IP.size()))temp.emplace_back(*ip);
		}


	}

	return (temp);

}