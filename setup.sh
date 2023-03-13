if [ -d "build" ]
then
	echo build dir exists
	echo deleting existing build dir
	rm -rf build
fi

echo creating build dir
mkdir build
cd build

echo Calling CMake
cmake -G Xcode -S ..

cd ..
