class Solution
{
public:
	int numberOfDays(int Y, int M)
	{
		if (M == 2)
		{
			if (Y % 4 == 0)
			{
				if (Y % 100 == 0)
				{
					if (Y % 400 == 0)
					{
						return 29;
					}
					return 28;
				}
				return 29;
			}
			return 28;
		}
		int ret = 0;
		switch (M)
		{
		case 1:
			ret = 31;
			break;
		case 3:
			ret = 31;
			break;
		case 4:
			ret = 30;
			break;
		case 5:
			ret = 31;
			break;
		case 6: // June
			ret = 30;
			break;
		case 7:
			ret = 31;
			break;
		case 8:
			ret = 31;
			break;
		case 9:
			ret = 30;
			break;
		case 10:
			ret = 31;
			break;
		case 11:
			ret = 30;
			break;
		case 12:
			ret = 31;
			break;
		}
		return ret;
	}
};