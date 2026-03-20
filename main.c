#include <stdio.h>
#include <stdlib.h>

#include "program.h"

int main(int c, char** v) {
	// Check if the number of arguments is correct (program name + 2 numbers)
	if (c != 3) {
		printf("Usage: %s <num1> <num2>\n", v[0]);
		return 1;
	}

	printf("perimeter: %s, ", perimeter(v[1], v[2]));
	printf("area: %s", area(v[1], v[2]));

	return 0;
}

// Argument 기반 컴파일 및 실행 진행 과정
// 1. 컴파일: 솔루션 탭에서 "Arguments-based Add" 프로젝트를 선택한 후, 빌드 메뉴에서 "빌드 솔루션"을 클릭하여 컴파일합니다.
// 2. 실행: 빌드가 완료된 후, CLI 혹은 터미널을 통해 해당 프로그램의 exe 파일이 있는 경로 이동하여 다음과 같이 실행합니다.
//    - 경로 이동: `cd <프로젝트 빌드 경로>` (예시: `cd ...\Arguments-based Add\x64\Debug`, ...의 앞은 프로젝트 폴더 위치)
//    - 프로그램 실행: `.\program.exe 5 10` (예시로 5와 10을 더하는 경우)
