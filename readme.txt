1. telescope 安装需要fd和ripgrep
    下载：
    Plug 'BurntSushi/ripgrep'
    Plug 'sharkdp/fd'

    安装(PlugInstall)：
    需要用cargo工具，对两个目录进行编译, cargo build --release
    此工具安装:
        curl https://sh.rustup.rs -sSf | sh
        默认路径 ~/.cargo

2. coc.nvim安装
    coc.python 与 coc.jedi不能同时安装，如果安装coc.jedi,,则需要卸载掉(:CocUninstall coc.python)
    coc.jedi, 使用python3.6, 因为coc.jedi运行需要给创建虚拟环境.env，，故需要选安装sudo apt-get install python3.6-venv,
    还有需要安装jedi-language-server,
    QS:
    c
    c/extensions/node_modules/coc-jedi/.env安装的jedi-language-server==0.37.0与~/.local/lib/python3.6/site-packages中jedi_language_server==0.35.1
    版本不一致，解决办法:coc/extensions/node_modules/coc-jedi/lib/index.js中修改版本号，package.js中修改版本号
   
    coc安装常用命令：
    :CocInstall coc.jedi
    :CocUninstall  coc.jedi
    :CocList extensions
    :CocInfo
    :CocCommand python.setInterpreter "~/.local/bin/python3"
    
    解决此问题：
    在dotfile/.config/coc/extensions/node_modules/coc-jedi/package.json中
    将jedi.enable设置 false
