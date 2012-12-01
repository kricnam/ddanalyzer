/*
 * User.h
 *
 *  Created on: Dec 1, 2012
 *      Author: mxx
 */

#ifndef USER_H_
#define USER_H_
#include <Wt/Dbo/Dbo>
#include <string>
#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/Auth/Dbo/AuthInfo>

using namespace Wt;
using namespace std;

namespace DataCenter
{
class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
typedef Wt::Dbo::collection< Wt::Dbo::ptr<User> > Users;

class User
{
public:
	User();
	virtual ~User();
	enum Role
	{
		Admin = 0, Worker = 1, Guest
	};

	string name;
	string password;
	Role role;
	WDateTime last_login;

	template<class Action>
	void persist(Action& a)
	{
		Dbo::field(a, name, "name");
		Dbo::field(a, password, "password");
		Dbo::field(a, role, "role");
		Dbo::field(a, last_login, "last_login");
	}
};

} /* namespace DataCenter */
#endif /* USER_H_ */
