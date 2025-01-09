#include "validators.h"

int	ft_check_extension(const char *file)
{
	const char	*dot;

	dot = ft_strrchr(file, '.');
	if (!dot || dot == file)
		return (0);
	if (ft_strlen(dot) != 4)
		return (0);
	return (!ft_strncmp(dot, ".ber", 4));
}
