PYTHON=uv run --link-mode=copy python
FLAKE8=uv run flake8
MYPY=uv run mypy
CHECK_UV=command -v uv

INSTALL_UV = curl -LsSf https://astral.sh/uv/install.sh | sh

MYPY_FLAGS=--warn-return-any --warn-unused-ignores --ignore-missing-imports \
--disallow-untyped-defs --check-untyped-defs \
--explicit-package-bases \

SRC_FILES=a_maze_ing.py src/
CONFIG=config.txt

.PHONY: all install run debug clean lint lint-strict build

all: install run

install:
	@if	! $(CHECK_UV) > /dev/null 2>&1; then \
			echo "UV not installed. Installing..."; \
			$(INSTALL_UV); \
	fi
	@echo "Installing project dependencies using uv..."
	uv sync --link-mode=copy

run:
	$(PYTHON) a_maze_ing.py $(CONFIG)

debug:
	$(PYTHON) -m pdb a_maze_ing.py $(CONFIG)

clean:
	find . -type d -name "__pycache__" -exec rm -rf {} +
	find . -type d -name ".mypy_cache" -exec rm -rf {} +
	rm -rf .mypy_cache
	rm -rf .coverage
	rm -rf .venv
	rm -f uv.lock
	rm -f output_lab.txt

lint:
	@clear
	@status=0; \
	$(FLAKE8) $(SRC_FILES) || status=$$?; \
	$(MYPY) $(SRC_FILES) $(MYPY_FLAGS) || status=$$?; \
	exit $$status

lint-strict:
	@clear
	@status=0; \
	$(FLAKE8) $(SRC_FILES) || status=$$?; \
	$(MYPY) $(SRC_FILES) $(MYPY_FLAGS) --strict || status=$$?; \
	exit $$status

build:
	python3 -m build
