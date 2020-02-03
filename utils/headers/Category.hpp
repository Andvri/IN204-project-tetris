#ifndef CATEGORY_HPP
#define CATEGORY_HPP


// Entity/scene node category, used to dispatch commands
namespace Category
{
	enum Type
	{
		None				= 0,
		Scene				= 1 << 0,
		PlayerSquare		= 1 << 1
	};
}

#endif