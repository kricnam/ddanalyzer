/*
 * Worker.h
 *
 *  Created on: Dec 1, 2012
 *      Author: mxx
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <string>
#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/Auth/Dbo/AuthInfo>

using namespace Wt;
using namespace Wt::Dbo;
using namespace std;

namespace DataCenter
{
class Worker;
typedef Auth::Dbo::AuthInfo<Worker> AuthInfo;
typedef collection<ptr<Worker> > Users;

class Worker: public Wt::Dbo::Dbo<Worker>
{
public:
	Worker();
	virtual ~Worker();
	enum Role
	{
		Admin = 0, General = 1, Guest
	};

	string name;
	Role role;
	WDateTime last_login;

	template<class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::field(a, role, "role");
		Wt::Dbo::field(a, last_login, "last_login");
	}

};

} /* namespace DataCenter */
#endif /* USER_H_ */
