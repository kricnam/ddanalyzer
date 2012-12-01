/*
 * User.cpp
 *
 *  Created on: Dec 1, 2012
 *      Author: mxx
 */

#include "User.h"
#include <Wt/Auth/Dbo/AuthInfo>
#include <Wt/Dbo/Impl>

namespace DataCenter
{


User::User() :
		role(Guest)
{

}

User::~User()
{

}

} /* namespace DataCenter */
