<?php
/** The base configuration for WordPress
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 */

/** The name of the database for WordPress */
define('DB_NAME', 'Base');

/** MySQL database username */
define('DB_USER', 'fcil');

/** MySQL database password */
define('DB_PASSWORD', '123');

/** MySQL hostname */
define('DB_HOST', 'mariadb');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8');

//** Redis cache settings. */
define('WP_CACHE', true);
define('WP_CACHE_KEY_SALT', 'fcil.42.fr');

//** Try Redis container */
define('WP_REDIS_HOST', 'redis');
define('WP_REDIS_PORT', 6379);
// define( 'WP_REDIS_PASSWORD', '$REDIS_PWD' );
define('WP_REDIS_TIMEOUT', 1);
define('WP_REDIS_READ_TIMEOUT', 1);
define('WP_REDIS_DATABASE', 0);


/** Authentication Unique Keys and Salts.
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 */

define('AUTH_KEY',         'qvQz(eqh}5~;S5TR#R:T&C?V;`9^SKZj.Z^]z?i`mhO?E-g0jA(3|T:<q?uBK#36');
define('SECURE_AUTH_KEY',  'I]Lar9Kn_+|>6Yn>QuxXX~~H<vwZW=J!|_O06B-b_-M_{iPd^`S~O#rL8[k#_3Qx');
define('LOGGED_IN_KEY',    'B,,slhS>=QaZ4a,[$3d}w@3G>t=-rVn|af;e^Y1N)|P De0]PJ-AoG6I]Oa;`}hA');
define('NONCE_KEY',        '$-1g>/*G+^W3NusCW3<+li GS%jG#emQ_c!kpUd@`hvLt@9Mr2,<2E)+@sFT@&_f');
define('AUTH_SALT',        'G(cJz*p)_fBbi:}Sb&gF+Kx{#w-MVHM?J.>jm.H=l)L~dqFaQ|-AN3/-/M DD@pg');
define('SECURE_AUTH_SALT', '6&W-;`Q4wz{m|o`Az/ZS9:~f5H0*45C[w95U[S|N+v%39`x~l};fSjlY4C[Ept2G');
define('LOGGED_IN_SALT',   '+qr-6C[G>uB=+>uWrU>XsV} fEosQvMNPoVED==+QW]}C{J [:p-ko%&@Et_!b$@');
define('NONCE_SALT',       'Q!G2)qR(Gdzy(7>m,+M+]Geac%R9+VAIW0EoslA+C)<> w=d9`pygGtn4+.U~?1=');

/** WordPress Database Table prefix. */
$table_prefix = 'wp_';

/** For developers: WordPress debugging mode. */
define( 'WP_DEBUG', false );

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
?>
