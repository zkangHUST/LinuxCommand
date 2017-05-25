1.安装git
---
首先确保电脑联网,输入下列命令安装git.
乌班图环境下输入
```
sudo apt-get install git
```
在CentOS环境下,输入
```
yum install git
```

在Windows环境下,可以安装git bash.输入
```
git --version
```
可以查看安装的git版本

2.在gitlab上新建仓库
---
略

3.git 设置
---
创建好仓库之后,会显示Command line instructions界面.按照提示,设置设置用户名和邮箱
```
git config --global user.name "Zheng Kang"              //将用户名替换成自己的用户名
git config --global user.email "1473345713@qq.com"      //邮箱替换成自己gitlab的注册邮箱
```
4.将刚才创建的仓库克隆到本地
---
现在选择一个文件夹，将刚才创建的仓库克隆到本地.比如,我要将刚才创建的test仓库克隆到E盘根目录下,首先在桌面上右击打开git bash.
输入
```
 cd  E:/
```
跳到E盘根目录下,然后输入
```
git clone https://zhengkang@gitlab.imchub.cn/zhengkang/test.git
```
会弹出提示信息,提示你clone的是一个空的仓库.
```
Cloning into 'test'...
warning: You appear to have cloned an empty repository.
```
克隆完成后,会发现在E盘多了一个名为test的空文件夹(实际上并不是空的,有两个隐藏文件在维护这个仓库)

5.创建一个文件,并提交到仓库
---
现在输入cd test进入本地仓库,然后输入
```
vim readme.md
```
随便写点什么,然后保存退出.现在输入
```
git status
```
显示仓库的状态
```
On branch master

Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        readme.md

nothing added to commit but untracked files present (use "git add" to track)

```
这个提示说readme.md这个文件没有被跟踪到.现在输入
```
git add readme.md
```
再次输入git status，显示提示信息为
```
On branch master

Initial commit

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

        new file:   readme.md

```
就是说现在readme.md这个文件被提交到了暂存区,下一步就是等待被正式提交到版本库.输入
```
git commit -m "create readme.md"
```
将readme.md文件正式提交到版本库.双引号里面的内容可以写一些简单的备注信息.

6.修改readme.md文件,重新提交
---
打开readme.md文件,修改文件如下
```
This is a test file to learn git.
---
                        2017.5.1
```
再次输入
```
git add readme.md
git commit -m "update readme.md"
```
将readme.md文件提交到版本库

7.查看提交日志
---
输入
```
git log 
```
可以查看git提交日志
```
commit 04999e92426b1f03e03edab050d711f7ab20aeb1
Author: ZhengKang <1473345713@qq.com>
Date:   Mon May 1 18:45:46 2017 +0800

    update readme.md

commit 794b8cc457df62c6aae1bec480a6ee7e7f22606b
Author: ZhengKang <1473345713@qq.com>
Date:   Mon May 1 18:40:07 2017 +0800

    create readme.md

```
可以很清晰的看到提交的作者,日期以及备注信息.

8.版本回退
---
如果发现当前版本代码被改乱了,或者有别的问题,需要恢复之前提交的版本,那么输入
```
git reset --hard HEAD^
```
回退到上一个版本,HEAD^表示当前版本的上一个版本,HEAD^^表示上上个版本,HEAD~100表示往前100个版本.

9.推送到远程仓库
---
在本地仓库中修改好代码并提交到本地仓库之后,如果想推送到远程仓库.输入
```
git push -u origin master
```
由于远程库是空的，我们第一次推送master分支时，加上了-u参数，Git不但会把本地的master分支内容推送的远程新的master分支，
还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令,直接输入
```
git push
```
即可将本地仓库的内容推送到远程仓库.


10.分支管理
---
几乎每一种版本控制系统都以某种形式支持分支。使用分支意味着你可以从开发主线上分离开来，然后在不影响主线的同时继续工作。
每次commit之后,Git都把它们串成一条时间线,这条时间线就是一个分支.现在我们的仓库只有一条时间线,在Git里，这个分支叫主分支,即master分支.HEAD严格来说不是指向提交.而是指向master.master才是指向提交的，所以,HEAD指向的就是当前分支.

![](http://www.liaoxuefeng.com/files/attachments/0013849087937492135fbf4bbd24dfcbc18349a8a59d36d000/0)

11.创建分支
---
输入git branch可以查看分支,输入git checkout -b branchA可以创建一个名为branchA的分支

12.切换分支
---
git chechout branchA 可以切换到branchA分支上

13.合并分支
---
首先切换到master分支,然后输入git merge branchA即可将branchA分支合并到master分支.

14.删除分支
---
分支合并完成之后,可以把banchA分支删除掉
git branch -d branchA




**如果不习惯使用命令行,也有一种简单的办法,直接在网页上点击界面右上方的‘+’号,上传文件,效果是一样的.**

相关链接:
---


1.[廖雪峰git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

2.[git bash 下载](https://git-for-windows.github.io/)
