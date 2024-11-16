SOURCE_DIR=.
BUILD_DIR=./.build
EXECUTABLE=flappy

build:
	cmake -DCMAKE_BUILD_TYPE=Debug -S ${SOURCE_DIR} -B ${BUILD_DIR}
	cmake --build ${BUILD_DIR}

build-release:
	cmake -DCMAKE_BUILD_TYPE=Release -S ${SOURCE_DIR} -B ${BUILD_DIR}
	cmake --build ${BUILD_DIR}
	
clean:
	rm -rf ${BUILD_DIR} ${EXECUTABLE}

run:
	./${BUILD_DIR}/${EXECUTABLE}
