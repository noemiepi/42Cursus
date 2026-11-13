import sys
import importlib.util
import subprocess


# verification des dependances dans le venv
def check_dependencies() -> bool:
    dependencies = ["pydantic", "mypy", "flake8", "poetry"]
    missing = [lib for lib in dependencies if
               importlib.util.find_spec(lib) is None]
    if missing:
        try:
            print("\n**** Installs dependencies using poetry ****")
            subprocess.check_call([sys.executable, "-m", "poetry",
                                   "install"])
            importlib.invalidate_caches()
            return True
        except Exception as e:
            print(f"\033[1;31mError during installation of {e}\033[0m")
        return False
    return True
