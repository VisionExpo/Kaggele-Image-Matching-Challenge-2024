'''# Template to create file and folder structure

import os
from pathlib import Path
import logging

# logging string
logging.basicConfig(level=logging.INFO, format='[%(asctime)s]: %(message)s:')

project_name = '2d_to_3d'

# make a list of files and folders
list_of_files = [
    ".github/workflows/.gitkeep",
    "data/train",
    "data/test",
    "Docker",
    "models",
    f"src/{project_name}/__init__.py",
    f"src/{project_name}/components/__init__.py",
    f"src/{project_name}/utils/__init__.py",
    f"src/{project_name}/config/__init__.py",
    f"src/{project_name}/config/configuration.py",
    f"src/{project_name}/pipeline/__init__.py",
    f"src/{project_name}/entity/__init__.py",
    f"src/{project_name}/constants/__init__.py",
    "config/config.yaml",
    "dvc.yaml",
    "params.yaml",
    "requirements.txt",
    "setup.py",
    "research/trials.ipynb",
    "templates/index.html"
    ""
]

for filepath in list_of_files:
    filepath = Path(filepath)
    filedir, filename = os.path.split(filepath)

    if filedir != "":
        os.makedirs(filedir, exist_ok=True)
        logging.info(f"Creating directory: {filedir} for the file: {filename}")

    if (not os.path.exists(filepath)) or (os.path.getsize(filepath) == 0):
        with open(filepath, "w") as f:
            pass
        logging.info(f"Creating empty file: {filepath}")

    else:
        logging.info(f"{filename} already exists")'''

import os
project_name = "2d_to_3d"  # Replace with your desired project name


def create_project_structure():
    """
    Creates the project directory structure with essential files.
    """

    # Create main directories
    os.makedirs(".github/workflows", exist_ok=True)
    os.makedirs("data/train", exist_ok=True)
    os.makedirs("data/test", exist_ok=True)
    os.makedirs("docker", exist_ok=True)  # Optional
    os.makedirs("models", exist_ok=True)
    os.makedirs("src/" + project_name, exist_ok=True)
    os.makedirs("templates", exist_ok=True)
    os.makedirs("tests/test_data", exist_ok=True)
    os.makedirs("tests/unit", exist_ok=True)
    os.makedirs("tests/integration", exist_ok=True)

    # Create subdirectories within src/project_name
    src_dir = os.path.join("src", project_name)
    os.makedirs(os.path.join(src_dir, "components"), exist_ok=True)
    os.makedirs(os.path.join(src_dir, "config"), exist_ok=True)
    os.makedirs(os.path.join(src_dir, "constants"), exist_ok=True)
    os.makedirs(os.path.join(src_dir, "entity"), exist_ok=True)
    os.makedirs(os.path.join(src_dir, "pipeline"), exist_ok=True)
    os.makedirs(os.path.join(src_dir, "utils"), exist_ok=True)

    # Create empty __init__.py files in relevant directories
    init_files = [
        os.path.join(src_dir, "__init__.py"),
        os.path.join(src_dir, "components", "__init__.py"),
        os.path.join(src_dir, "config", "__init__.py"),
        os.path.join(src_dir, "constants", "__init__.py"),
        os.path.join(src_dir, "entity", "__init__.py"),
        os.path.join(src_dir, "pipeline", "__init__.py"),
        os.path.join(src_dir, "utils", "__init__.py"),
    ]
    for file in init_files:
        with open(file, "w") as f:
            pass

    # Create essential files
    with open(os.path.join(src_dir, "config", "configuration.py"), "w") as f:
        f.write("# Configuration file for the project\n")
    with open(os.path.join(src_dir, "web_app.py"), "w") as f:
        f.write("# Main web app entry point\n")
    with open(os.path.join("templates", "index.html"), "w") as f:
        f.write("# Main website template\n")
    with open("requirements.txt", "w") as f:
        f.write("# List of project dependencies\n")
    with open("README.md", "w") as f:
        f.write("# Project documentation\n")


if __name__ == "__main__":
    create_project_structure()
    print(f"Project structure for '{project_name}' created successfully!")