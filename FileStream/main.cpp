# include <iostream>
# include <fstream>

bool LoadFile(const std::string& fileName)
{
	//exception
	// 
	// 1. 파일 스트림 객체 생성
	//	1.1 모드를 지정 ( 읽기/쓰기/텍스트/바이너리모드 )
	//	1.2 파일스트림 객체는 생성자를 통해 파일이름을 준다.
	//	1.3 빈 오브젝트 생성 -> 파일 열기
	std::ifstream ifs(fileName);
	
	if (!ifs) // operator overloading를 통해서 !를 쓸 수 있는 것이다.
	{
		std::cout << fileName << "을 찾을 수 없습니다." << std::endl;
		return false;
	}
	// 
	// 2. 파일 작업
	//	2.1 스트림 연사자 사용 가능
	//	2.2 멤버 함수 사용 가능
	/*char ch;
	while (ifs >> ch)
	{
		if (ifs.bad())
		{
			std::cout << "파일이 손상되었습니다." << std::endl;
			ifs.close();
			return false;
		}

		if (ifs.fail())
		{
			std::cout << " 의도치않은 작업입니다. " << std::endl;
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
	// 3. 작업이 끝나면 꼭 파일 닫기 (아 닫으면 다른 애들이 그 파일을 못씀!)
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

	// Platform independence : 윈도우, 안드로이드 등 다 된다!!
}