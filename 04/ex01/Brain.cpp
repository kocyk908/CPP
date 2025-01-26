#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->ideas[index]);
}