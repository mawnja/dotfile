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
   
    coc安装常用命令：
    :CocInstall coc.jedi
    :CocUninstall  coc.jedi
    :CocList extensions
    :CocInfo
    :CocCommand python.setInterpreter "~/.local/bin/python3"
    
    解决此问题：
    在dotfile/.config/coc/extensions/node_modules/coc-jedi/package.json中
    将jedi.enable设置 false

1. 为neovim添加python支持

python3 -m pip install --user --upgrade pynvim
python3 -m pip install -I --upgrade greenlet
pip3 list
:checkhealth

2. rg安装

cargo install ripgrep

3.  ./vim/plugin/fd编译 

cargo build --release
cargo install --path

4.npm下载加速
npm config set registry https://registry.npmmirror.com
npm config set registry https://registry.npm.taobao.org
npm config set registry https://npm.alyun.com
npm config set registry https://mirrors.cloud.tencent.com/npm/
npm config set registry https://mirrors.huaweicloud.com/repository/npm/
npm config set registry https://registry.npmjs.org/ #官网
npm config get registry #查看当前的镜像源

npm install -g neovim #npm支持neovim

5. tree-sitter提示不支持 lua, vimdoc
:TSUpdate lua 
:TSUpdate vimdoc

6.  jedi_language_server不匹配问题解决:

coc-jedi 0.30.1 需要jedi_language_server 0.35.1，npm==0.36.1 python>=3.6 pypi==0.41.4  node > 8.10.0
如果为python3.6,则只能安装coc-jedi@0.30.1
:CocInstall coc-jedi@0.30.1

pip install jedi-language-server==0.35.1 -i https://pypi.tuna.tsinghua.edu.cn/simple/ --trusted-host pypi.douban.com

7. Server language.clangd failed to start: Launching server "languageserver.clangd" using command clangd
解决:
(1)remove the clangd in coc-setting.json
(2):CocInstall coc-clangd
(3):CocCommad clangd.install

8. [coc.nvim] Invalid InitializationOptions, using defaults: 1 validation error for InitializationOptions
markupKindPreferred
  value is not a valid enumeration member; permitted: 'plaintext', 'markdown' (type=type_error.enum; enum_values=[<MarkupKind.PlainText: 'plaintext'>, <
MarkupKind.Markdown: 'markdown'>])

解决：
在 coc-settings.json中添加 "jedi.markupKindPreferred": "plaintext",

9. coc-jedi 与 coc-vimlsp会发生冲突

10. 按tab键时,报错unknown function: <SNR>103_check_back_space
解决:
在.config/nvim/init.vim中将pumvisible改为coc#pum#visible

11. other
pip install https://files.pythonhosted.org/packages/a6/a4/956ef96a52e1735ee1d494e30f274f6d3cd2b7fd18397731e6fd11035d8b/jedi_language_server-0.41.4-py3-none-any.whl
https://github.com/neovim/neovim/releases/
