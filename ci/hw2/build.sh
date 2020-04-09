# Build process lib
mkdir -p hw2/loglib/build
cd hw2/loglib/build
cmake ..
make
cd ../../..

# Build samples
mkdir -p hw2/samples/demo/build
cd hw2/samples/demo/build
cmake ..
make
cd ../../../..
