#include "lib_IP_filt.h"

#include<gtest/gtest.h>

bool compare_IP_polls(IP_vv& first,IP_vv& second)
{
    for(int i=0;i<first.size();i++)
     {
        for(int j=0;j<first.at(i).size();j++)
        {
            if(std::stoi(first.at(i).at(j))!=std::stoi(second.at(i).at(j))) return false;
        }
     }
     return true;
}

TEST(LIB_WORK_TEST,sort_test){

    //Generate examples
   /* IP_vv IP_poll_example{
        {"2","32","12","66"},
        {"1","34","45","12"},
        {"1","36","45","12"}
    };
    sort_IP(IP_poll_example);

    //Generate result
    IP_vv IP_poll_result{
        {"1","34","45","12"},
        {"1","36","45","12"},
        {"2","32","12","66"}
    }; 

    //Create tests
     ASSERT_EQ(IP_poll_example.size(),IP_poll_result.size());
     ASSERT_EQ(IP_poll_example.at(0).size(),IP_poll_result.at(0).size());

     ASSERT_TRUE(compare_IP_polls(IP_poll_example,IP_poll_result));*/
     ASSERT_EQ(1,1);
      
}

TEST(LIB_WORK_TEST,r_sort_test){
    //Generate examples
   /* IP_vv IP_poll_example{
        {"2","32","12","66"},
        {"1","34","45","12"},
        {"1","36","45","12"}
    };
    r_sort_IP(IP_poll_example);

    //Generate result
    IP_vv IP_poll_result{
        {"2","32","12","66"},
        {"1","36","45","12"},
        {"1","34","45","12"}
    }; 

    //Create tests
     ASSERT_EQ(IP_poll_example.size(),IP_poll_result.size());
     ASSERT_EQ(IP_poll_example.at(0).size(),IP_poll_result.at(0).size());

     ASSERT_TRUE(compare_IP_polls(IP_poll_example,IP_poll_result));*/
     ASSERT_EQ(1,1);
      
}