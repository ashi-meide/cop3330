# This entire makefile is just a build orchestrator
.PHONY: _validate _usage build test submit clean

# Notify user to specify what assignment to build
_usage:
	@printf 'Usage:\n'
	@printf '  make [build|test|submit|clean] ASSIGNMENT=[1|2|3|4]\n'

# Validate assignment selection
_validate:
    # Check that ASSIGNMENT variable is defined
    ifndef ASSIGNMENT
	@printf '\357\200\215 ASSIGNMENT was not specified.\n'
	@$(MAKE) usage
	@exit 1
    endif

    # Validate that ASSIGNMENT is an integer within range
	@case "$(ASSIGNMENT)" in                                                   \
        1|2|3|4 ) ;;                                                           \
        ''|*[!0-9]* )                                                          \
            printf '\357\200\215 ASSIGNMENT is not a valid integer.\n';        \
            $(MAKE) usage;                                                     \
            exit 1 ;;                                                          \
        * )                                                                    \
            printf '\357\200\215 ASSIGNMENT is outside valid range [1, 4].\n'; \
            $(MAKE) usage;                                                     \
            exit 1 ;;                                                          \
    esac

build: _validate
	@printf '\357\202\255 Building assignment $(ASSIGNMENT)...\n'
	@$(MAKE) -C assignment$(ASSIGNMENT)/submission
	@printf '\357\200\214 Built assignment $(ASSIGNMENT) to assignment$(ASSIGNMENT)/submission\n'

test: _validate build
	@printf '\357\202\256 Running tests for assignment $(ASSIGNMENT)...\n'
	@cd assignment$(ASSIGNMENT)/submission \
	;	../scripts/test.sh
	@printf '\357\200\214 All tests passed!\n'
	@$(MAKE) clean ASSIGNMENT=$(ASSIGNMENT)

submit: _validate test
	@printf '\357\207\206 Submitting assignment $(ASSIGNMENT)...\n'
	@cd assignment$(ASSIGNMENT)/submission        \
	;	export READTAR='../../scripts/submit.sh'  \
	;	../scripts/submit.sh

clean: _validate
	@printf '\357\200\224 Cleaning up assignment $(ASSIGNMENT)...\n'
	@cd assignment$(ASSIGNMENT)/submission \
	;	../../scripts/clean.sh             \
	;	../scripts/clean.sh
	@printf '\357\200\214 Cleaned up assignment $(ASSIGNMENT) build artifacts.\n'
