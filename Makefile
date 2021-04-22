run: medians
	@printf "\ntest case 1: "
	python interactive_runner.py python3 local_testing_tool.py 0 -- ./medians

	@printf "\ntest case 2: "
	python interactive_runner.py python3 local_testing_tool.py 1 -- ./medians

	@printf "\ntest case 3: "
	python interactive_runner.py python3 local_testing_tool.py 2 -- ./medians

medians: medians.cpp
	g++ medians.cpp -o medians