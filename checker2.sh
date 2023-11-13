#!/bin/bash

SIMPLE_SHELL="./simple_shell"
PROMPT="simple_shell$ "  # Replace with the actual prompt of your shell

test_command() {
	local command="$1"
	local expected="$2"

	echo "$command" | $SIMPLE_SHELL > output.txt
	# Check for the presence of the prompt after the command
	if ! grep -qF "$PROMPT" output.txt; then
		echo "FAIL: Prompt not displayed after the command"
		cat output.txt
		return 1
	fi
	# Check for the command output
	if [ -n "$expected" ] && ! grep -qF "$expected" output.txt; then
		echo "FAIL: Command output not as expected"
		cat output.txt
		return 1
	fi
	echo "PASS: Command '$command' passed"
}

test_not_found() {
	local command="$1"
	local expected="command not found"

	echo "$command" | $SIMPLE_SHELL > output.txt
	# Check for the specific error message
	if ! grep -qF "$expected" output.txt; then
		echo "FAIL: Expected error message not found"
		cat output.txt
		return 1
	fi
	echo "PASS: Command '$command' correctly handled as not found"
}

test_eof() {
	printf "\004" | $SIMPLE_SHELL > output.txt
	if [ -s output.txt ]; then
		echo "FAIL: Output should be empty on EOF"
		cat output.txt
		return 1
	fi
	echo "PASS: EOF correctly handled with no output"
}

# Run the tests
test_command "ls" ""
test_not_found "nonexistentcommand"
test_eof

# If all tests passed
echo "All tests passed."
