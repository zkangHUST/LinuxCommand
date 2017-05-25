1.什么是git
---
git是Linus Torvalds用C写的一个分布式版本控制系统.最开始是用于Linux系统的源码维护.

2.分布式和集中式
---
![](http://www.liaoxuefeng.com/files/attachments/001384860735706fd4c70aa2ce24b45a8ade85109b0222b000/0)

集中式版本控制系统，版本库是集中存放在中央服务器的，而干活的时候，用的都是自己的电脑，所以要先从中央服务器取得最新的版本，然后开始干活，干完活了，再把自己的活推送给中央服务器.
集中式版本控制系统最大的毛病就是必须联网才能工作，如果在局域网内还好，带宽够大，速度够快，可如果在互联网上，遇到网速慢的话，可能提交一个10M的文件就需要5分钟，速度很慢。
集中式版本控制系统有SVN,CVS等.

![](http://www.liaoxuefeng.com/files/attachments/0013848607465969378d7e6d5e6452d8161cf472f835523000/0)

那分布式版本控制系统与集中式版本控制系统有何不同呢？首先，分布式版本控制系统根本没有“中央服务器”，每个人的电脑上都是一个完整的版本库，这样，你工作的时候，就不需要联网了，因为版本库就在你自己的电脑上。既然每个人电脑上都有一个完整的版本库，那多个人如何协作呢？比方说你在自己电脑上改了文件A，你的同事也在他的电脑上改了文件A，这时，你们俩之间只需把各自的修改推送给对方，就可以互相看到对方的修改了。

和集中式版本控制系统相比，分布式版本控制系统的安全性要高很多，因为每个人电脑里都有完整的版本库，某一个人的电脑坏掉了不要紧，随便从其他人那里复制一个就可以了。而集中式版本控制系统的中央服务器要是出了问题，所有人都没法干活了。

在实际使用分布式版本控制系统的时候，其实很少在两人之间的电脑上推送版本库的修改，因为可能你们俩不在一个局域网内，两台电脑互相访问不了，也可能今天你的同事病了，他的电脑压根没有开机。因此，分布式版本控制系统通常也有一台充当“中央服务器”的电脑，但这个服务器的作用仅仅是用来方便“交换”大家的修改，没有它大家也一样干活，只是交换修改不方便而已。

3.安装git
---
首先确保电脑联网,在Linux环境下输入以下命令安装git.
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

4.在gitlab上新建仓库
---
略

5.git 设置
---
创建好仓库之后,会显示Command line instructions界面.按照提示,设置设置用户名和邮箱
```
git config --global user.name "Zheng Kang"              //将用户名替换成自己的用户名
git config --global user.email "1473345713@qq.com"      //邮箱替换成自己gitlab的注册邮箱
```
6.将刚才创建的仓库克隆到本地
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

7.创建一个文件,并提交到仓库
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

8.修改readme.md文件,重新提交
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

9.查看提交日志
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

10.版本回退
---
如果发现当前版本代码被改乱了,或者有别的问题,需要恢复之前提交的版本,那么输入
```
git reset --hard HEAD^
```
回退到上一个版本,HEAD^表示当前版本的上一个版本,HEAD^^表示上上个版本,HEAD~100表示往前100个版本.

11.推送到远程仓库
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


12.分支管理
---
几乎每一种版本控制系统都以某种形式支持分支。使用分支意味着你可以从开发主线上分离开来，然后在不影响主线的同时继续工作。
每次commit之后,Git都把它们串成一条时间线,这条时间线就是一个分支.现在我们的仓库只有一条时间线,在Git里，这个分支叫主分支,即master分支.HEAD严格来说不是指向提交.而是指向master.master才是指向提交的，所以,HEAD指向的就是当前分支.

![](http://www.liaoxuefeng.com/files/attachments/0013849087937492135fbf4bbd24dfcbc18349a8a59d36d000/0)

13.创建分支
---
输入`git branch`可以查看分支,输入

```
git checkout -b branchA
```
可以创建一个名为branchA的分支

14.切换分支
---

```
git chechout branchA
```
可以切换到branchA分支上

13.合并分支
---

首先切换到master分支,然后输入
```
git merge branchA
```
即可将branchA分支合并到master分支.

15.删除分支
---
分支合并完成之后,可以把banchA分支删除掉

```
git branch -d branchA
```



**如果不习惯使用命令行,也有一种简单的办法,直接在网页上点击界面右上方的‘+’号,上传文件,效果是一样的.**

相关链接:
---


1.[廖雪峰git教程](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000)

2.[git bash 下载](https://git-for-windows.github.io/)

