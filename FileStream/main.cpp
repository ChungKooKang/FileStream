# include <iostream>
# include <fstream>

bool LoadFile(const std::string& fileName)
{
	//exception
	// 
	// 1. ���� ��Ʈ�� ��ü ����
	//	1.1 ��带 ���� ( �б�/����/�ؽ�Ʈ/���̳ʸ���� )
	//	1.2 ���Ͻ�Ʈ�� ��ü�� �����ڸ� ���� �����̸��� �ش�.
	//	1.3 �� ������Ʈ ���� -> ���� ����
	std::ifstream ifs(fileName);
	
	if (!ifs) // operator overloading�� ���ؼ� !�� �� �� �ִ� ���̴�.
	{
		std::cout << fileName << "�� ã�� �� �����ϴ�." << std::endl;
		return false;
	}
	// 
	// 2. ���� �۾�
	//	2.1 ��Ʈ�� ������ ��� ����
	//	2.2 ��� �Լ� ��� ����
	/*char ch;
	while (ifs >> ch)
	{
		if (ifs.bad())
		{
			std::cout << "������ �ջ�Ǿ����ϴ�." << std::endl;
			ifs.close();
			return false;
		}

		if (ifs.fail())
		{
			std::cout << " �ǵ�ġ���� �۾��Դϴ�. " << std::endl;
			ifs.close();
			return false;
		}

		std::cout << ch;
	}*/
	char ch;
	while (ifs) 
	{
		ifs.get(ch);
		std::cout << ch;
	}
	// 3. �۾��� ������ �� ���� �ݱ� (�� ������ �ٸ� �ֵ��� �� ������ ����!)
	ifs.close();

	return true;
}

int main()
{
	// programming
	
	LoadFile("Data/SimpleData.txt");
	// ==

	//window
	LoadFile("Data\\SimpleData.txt");

	// Platform independence : ������, �ȵ���̵� �� �� �ȴ�!!
}