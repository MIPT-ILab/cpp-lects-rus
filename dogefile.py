from pathlib import Path

from dogebuild_tex import Tex, DockerTexBinary


Tex(
    main_file=Path("cpp_lectures.tex"),
    tex_binary=DockerTexBinary("thomasweise/docker-texlive-full"),
)
