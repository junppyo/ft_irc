#ifndef ICOMMAND_HPP
# define ICOMMAND_HPP

#include <string>
#include <vector>

class Translator;
class Server;

class ICommand {
public:
	enum CommandType {
		PASS,
		NICK,
		USER,
		JOIN,
		PRIVMSG,
		PART,
		QUIT,
		KICK,
		OPER,
		KILL,
		PONG,
		UNKNOWN
	};
protected:
	Translator* translator;
	CommandType type;
public:
	ICommand(Translator* translator, CommandType type);
	virtual ~ICommand();
	CommandType getType() const;
	virtual void execute(Server& server, std::vector<std::string>& cmd, int fd) = 0;
};

#endif