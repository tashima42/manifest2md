# oras manifest json 2 md

```bash
make && cat manifest.json | ./manifest2md.o
```

Output:

```
  * rancher-components.txt: sha256:d7513aa4854688f6c1064c534bbb8609c7672121a7217accfe003e4d343d9404
  * rancher-data.json: sha256:3e6486588a42a02ce4d1d38bc48e9479c6f9acb5bb8fd1f0e4ed2f095ba455eb
  * rancher-images-origins.txt: sha256:e4f52963a7b54cade5eea6792e962d46f143b79b56fb0fc075a7c42e50650eb6
  * rancher-images-sources.txt: sha256:20c2f446d0a6f3d64fff5a09cf4b29788efcc4f9648f0e74d137a5aed91e179f
  * rancher-images.txt: sha256:20202793016939e299da0b8e8ded75b04c07ea14340c66105938c39f5b3ebded
  * rancher-load-images.ps1: sha256:3a73d33533d74d9fc70cfb4a57a85a598475c2b0e819ac1ca0adf767745e17b1
  * rancher-load-images.sh: sha256:92b95856fc79d92a226b3989f88cc06f259a2e68b77269c93ee128ff5f1a57ca
  * rancher-mirror-to-rancher-org.ps1: sha256:a78d9cf886c102ca5effd7c82ac8581408d3450ae9a0db9dda32ea02a802cbf2
  * rancher-mirror-to-rancher-org.sh: sha256:c1a03f08d3debd66184ac33c51431eeb37e4ac47433fd32d1bfe39d0dbe20544
  * rancher-rke-k8s-versions.txt: sha256:f38b0a03dd9b2f3855c99a754457bc6145002d62dffb14a0a78d17674b13b541
  * rancher-save-images.ps1: sha256:95c738678d1e5c2c962c351c07691ddc26d0e4eaa387a18b32991986d742fba6
  * rancher-save-images.sh: sha256:a0a1320d822b8ba020e8a2b9724d9f5a7e1ad6bafb566bc1759bf142d6c6d7b1
  * rancher-windows-images-sources.txt: sha256:865419c237614c0ae6a874c50a7643dfc5ed9d8db090c191caa776e7d41969fe
  * rancher-windows-images.txt: sha256:aa606270fcd2cc8cbc43b82e579a521e63388ae86f84355b40e5692d58093c8f
  * sha256sum.txt: sha256:f0e5f21bb1b6b52914c49caf3e940de20008324d7e64057419a3088b7020b1fb
```
