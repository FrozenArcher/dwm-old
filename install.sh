pkgname=dwm

cp config.def.h config.h

echo "==> building dwm..."
echo "  ==> compiling..."
make
echo "  ==> installing..."
sudo make install
sudo install -m644 -D LICENSE "/usr/share/licenses/$pkgname/LICENSE"
sudo install -m644 -D README.md "/usr/share/doc/$pkgname/README"
sudo install -m644 -D ./dwm.desktop "/usr/share/xsessions/dwm.desktop"
echo "==> build finished."
