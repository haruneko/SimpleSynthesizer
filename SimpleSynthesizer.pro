TEMPLATE = subdirs

SUBDIRS = \
    SimpleSynthesizerCore.pro \
    SimpleSynthesizerApp.pro \
    SimpleSynthesizerTest.pro

Core.subdir = SimpleSynthesizerCore.pro

App.subdir = SimpleSynthesizerApp.pro
App.depends = Core

Test.subdir = SimpleSynthesizerTest.pro
Test.depends = Core
