wget --no-check-certificate -O shadowsocks.sh https://raw.githubusercontent.com/teddysun/shadowsocks_install/master/shadowsocks.sh

chmod +x shadowsocks.sh

./shadowsocks.sh 2>&1 | tee shadowsocks.log

ssserver -c /etc/shadowsocks.json -d start/stop

wget --no-check-certificate https://github.com/teddysun/across/raw/master/bbr.sh

chmod +x bbr.sh

./bbr.sh
lsmod | grep bbr
check tcp_bbr

ffmpeg -i INPUT.mp4 -crf 18 -preset 6 -tune film -r 60 -s 1920x1080 -pix_fmt yuv420p -profile:v high -level 4.2 -g 590 -keyint_min 1 -maxrate 22M -bufsize 44M OUTPUT.mp4

ffmpeg -y -i INPUT.mp4 -pass 2 -b:v 5800k -preset 6 -tune film -r 60 -s 1920x1080 -pix_fmt yuv420p -profile:v high -level 4.2 -g 590 -keyint_min 1 -maxrate 22M -bufsize 44M OUTPUT.mp4

bash <(curl -L -s https://raw.githubusercontent.com/hijkpw/scripts/master/centos_install_v2ray.sh)
