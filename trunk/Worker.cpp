/*
 * User.cpp
 *
 *  Created on: Dec 1, 2012
 *      Author: mxx
 */

#include "Worker.h"
#include <Wt/Auth/Dbo/AuthInfo>
#include <Wt/Dbo/Impl>

namespace DataCenter
{


Worker::Worker() :
		role(Guest)
{

}

Worker::~Worker()
{

}

} /* namespace DataCenter */
