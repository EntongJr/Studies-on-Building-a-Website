-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               8.4.3 - MySQL Community Server - GPL
-- Server OS:                    Win64
-- HeidiSQL Version:             12.8.0.6908
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Dumping structure for table db_laundry.detail_pesanan
CREATE TABLE IF NOT EXISTS `detail_pesanan` (
  `id_detail` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_pesanan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_layanan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `subtotal` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`id_detail`) USING BTREE,
  KEY `FK_DETAIL_P_DIPILIH_D_LAYANAN` (`id_layanan`) USING BTREE,
  KEY `FK_DETAIL_P_TERDIRI_D_PESANAN` (`id_pesanan`) USING BTREE,
  CONSTRAINT `FK_DETAIL_P_DIPILIH_D_LAYANAN` FOREIGN KEY (`id_layanan`) REFERENCES `layanan` (`id_layanan`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `FK_DETAIL_P_TERDIRI_D_PESANAN` FOREIGN KEY (`id_pesanan`) REFERENCES `pesanan` (`id_pesanan`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.detail_pesanan: ~1 rows (approximately)
INSERT INTO `detail_pesanan` (`id_detail`, `id_pesanan`, `id_layanan`, `subtotal`) VALUES
	('DTL001', 'PSN001', 'LYN001', 9000.00);

-- Dumping structure for table db_laundry.jabatan
CREATE TABLE IF NOT EXISTS `jabatan` (
  `id_jabatan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_jabatan` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`id_jabatan`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.jabatan: ~2 rows (approximately)
INSERT INTO `jabatan` (`id_jabatan`, `nama_jabatan`) VALUES
	('JBT001', 'Admin'),
	('JBT002', 'Petugas Laundry');

-- Dumping structure for table db_laundry.keluhan
CREATE TABLE IF NOT EXISTS `keluhan` (
  `id_keluhan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_pesanan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `isi_keluhan` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci,
  `tanggal_keluhan` datetime DEFAULT NULL,
  `status_keluhan` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`id_keluhan`) USING BTREE,
  KEY `FK_KELUHAN_DIKELUHKA_PESANAN` (`id_pesanan`) USING BTREE,
  CONSTRAINT `FK_KELUHAN_DIKELUHKA_PESANAN` FOREIGN KEY (`id_pesanan`) REFERENCES `pesanan` (`id_pesanan`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.keluhan: ~0 rows (approximately)

-- Dumping structure for table db_laundry.layanan
CREATE TABLE IF NOT EXISTS `layanan` (
  `id_layanan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_layanan` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `harga_perkg` decimal(10,2) DEFAULT NULL,
  `berat_minimum` decimal(8,2) DEFAULT '1.00',
  `estimasi_hari` int DEFAULT NULL,
  `deskripsi` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci,
  PRIMARY KEY (`id_layanan`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.layanan: ~6 rows (approximately)
INSERT INTO `layanan` (`id_layanan`, `nama_layanan`, `harga_perkg`, `berat_minimum`, `estimasi_hari`, `deskripsi`) VALUES
	('LYN001', 'Cuci Basah', 5000.00, 8.00, 2, 'Cuci bersih tanpa pengeringan. Cocok untuk pakaian sehari-hari.'),
	('LYN002', 'Cuci Kering', 7000.00, 8.00, 2, 'Cuci dan keringkan sempurna. Siap pakai lebih cepat.'),
	('LYN003', 'Cuci Lipat Rapi Wangi', 6000.00, 3.00, 3, 'Cuci, keringkan, dan lipat rapi dengan pewangi pilihan.'),
	('LYN004', 'Cuci Setrika Wangi', 8000.00, 3.00, 3, 'Layanan lengkap: cuci, keringkan, setrika, dan wangi.'),
	('LYN005', 'Setrika Wangi', 6000.00, 3.00, 1, 'Khusus setrika pakaian yang sudah dicuci sendiri.'),
	('LYN006', 'Cuci Basah Express', 8000.00, 1.00, -1, 'Cuci 4 Jam Selesai');

-- Dumping structure for table db_laundry.metode_pembayaran
CREATE TABLE IF NOT EXISTS `metode_pembayaran` (
  `id_metode` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_metode` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`id_metode`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.metode_pembayaran: ~5 rows (approximately)
INSERT INTO `metode_pembayaran` (`id_metode`, `nama_metode`) VALUES
	('MTP001', 'Tunai'),
	('MTP002', 'Transfer Bank'),
	('MTP003', 'QRIS'),
	('MTP004', 'Dana'),
	('MTP005', 'OVO');

-- Dumping structure for table db_laundry.pelanggan
CREATE TABLE IF NOT EXISTS `pelanggan` (
  `id_pelanggan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_pelanggan` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `no_telepon` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `alamat` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci,
  `email` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `sandi` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`id_pelanggan`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.pelanggan: ~2 rows (approximately)
INSERT INTO `pelanggan` (`id_pelanggan`, `nama_pelanggan`, `no_telepon`, `alamat`, `email`, `sandi`) VALUES
	('PLG001', 'Andi Sapura', '081234567001 ', 'Surabaya ', 'andi@gmail.com', '$2y$10$3InolOv6WO7.TFITFeue2exe2U32fXm4/0xLTauBEqhWCccHkjm7C'),
	('PLG002', 'Sinta Ayu', '081234567002', 'Sidoarjo', 'sinta@gmail.com', '$2y$10$ShC/1N/Tqs0phs2tdM6WrO8kRSaTNvWxDDb68tauLPSHdowH/BV3S');

-- Dumping structure for table db_laundry.pembayaran
CREATE TABLE IF NOT EXISTS `pembayaran` (
  `id_pesanan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_pembayaran` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_metode` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `tanggal_bayar` datetime DEFAULT NULL,
  `jumlah_bayar` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`id_pesanan`,`id_pembayaran`) USING BTREE,
  KEY `FK_PEMBAYAR_DIGUNAKAN_METODE_P` (`id_metode`) USING BTREE,
  CONSTRAINT `FK_PEMBAYAR_DIBAYAR_V_PESANAN` FOREIGN KEY (`id_pesanan`) REFERENCES `pesanan` (`id_pesanan`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `FK_PEMBAYAR_DIGUNAKAN_METODE_P` FOREIGN KEY (`id_metode`) REFERENCES `metode_pembayaran` (`id_metode`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.pembayaran: ~1 rows (approximately)
INSERT INTO `pembayaran` (`id_pesanan`, `id_pembayaran`, `id_metode`, `tanggal_bayar`, `jumlah_bayar`) VALUES
	('PSN001', 'PAY001', 'MTP001', '2026-05-29 00:44:47', 9000.00);

-- Dumping structure for table db_laundry.pesanan
CREATE TABLE IF NOT EXISTS `pesanan` (
  `id_pesanan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_promo` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `id_pelanggan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_petugas` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_status` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `tanggal_pesanan` datetime DEFAULT NULL,
  `berat_cucian` decimal(5,2) DEFAULT NULL,
  `berat_dihitung` decimal(8,2) DEFAULT '1.00',
  `harga_per_kg` decimal(10,2) DEFAULT NULL,
  `total_harga` decimal(12,0) DEFAULT NULL,
  `status_pembayaran` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `catatan` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci,
  PRIMARY KEY (`id_pesanan`) USING BTREE,
  KEY `FK_PESANAN_DITERAPKA_PROMO` (`id_promo`) USING BTREE,
  KEY `FK_PESANAN_MELAKUKAN_PELANGGA` (`id_pelanggan`) USING BTREE,
  KEY `FK_PESANAN_MENANGANI_PETUGAS` (`id_petugas`) USING BTREE,
  KEY `FK_PESANAN_MENJADI_S_STATUS_P` (`id_status`) USING BTREE,
  CONSTRAINT `FK_PESANAN_DITERAPKA_PROMO` FOREIGN KEY (`id_promo`) REFERENCES `promo` (`id_promo`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `FK_PESANAN_MELAKUKAN_PELANGGA` FOREIGN KEY (`id_pelanggan`) REFERENCES `pelanggan` (`id_pelanggan`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `FK_PESANAN_MENANGANI_PETUGAS` FOREIGN KEY (`id_petugas`) REFERENCES `petugas` (`id_petugas`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `FK_PESANAN_MENJADI_S_STATUS_P` FOREIGN KEY (`id_status`) REFERENCES `status_pesanan` (`id_status`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.pesanan: ~1 rows (approximately)
INSERT INTO `pesanan` (`id_pesanan`, `id_promo`, `id_pelanggan`, `id_petugas`, `id_status`, `tanggal_pesanan`, `berat_cucian`, `berat_dihitung`, `harga_per_kg`, `total_harga`, `status_pembayaran`, `catatan`) VALUES
	('PSN001', 'PRO001', 'PLG001', 'PTG001', 'STS001', '2026-05-29 00:44:47', 12.00, 1.00, NULL, 9000, 'Belum Lunas', 'tolong yang bersih ya');

-- Dumping structure for table db_laundry.petugas
CREATE TABLE IF NOT EXISTS `petugas` (
  `id_petugas` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `id_jabatan` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_petugas` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `no_telepon` varchar(15) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `alamat` longtext CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci,
  `gaji` decimal(10,2) DEFAULT NULL,
  `email` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `sandi` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`id_petugas`) USING BTREE,
  KEY `FK_PETUGAS_DIMILIKI_JABATAN` (`id_jabatan`) USING BTREE,
  CONSTRAINT `FK_PETUGAS_DIMILIKI_JABATAN` FOREIGN KEY (`id_jabatan`) REFERENCES `jabatan` (`id_jabatan`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.petugas: ~3 rows (approximately)
INSERT INTO `petugas` (`id_petugas`, `id_jabatan`, `nama_petugas`, `no_telepon`, `alamat`, `gaji`, `email`, `sandi`) VALUES
	('PTG001', 'JBT001', 'Entong', '081234567890', 'Jl. Admin No. 1', 5000000.00, 'admin@gmail.com', '$2y$10$jzPHn.md7rjiLCxBIoTUSOOj4bu15mjexOL4HYKvyBsJceC8eX1OK'),
	('PTG002', 'JBT002', 'Budi', '081200001', 'Jl. Petugas No. 2', 3000000.00, 'petugas1@gmail.com', '$2y$10$gibsHb1fwI6GNUfshiAZMu.QE/2wmbCaRgD6UhOzkbYwcjlBaT9ZG'),
	('PTG003', 'JBT002', 'Rina', '081200002', 'Saudi arabia', 3000000.00, 'petugas2@gmail.com', '$2y$10$7ZE1w6ey0YNJ5L.lgoHs9eIG7hsIf4kADsWGDeE7fQsRAGkKmeT6e');

-- Dumping structure for table db_laundry.promo
CREATE TABLE IF NOT EXISTS `promo` (
  `id_promo` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_promo` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `diskon` decimal(5,2) DEFAULT NULL,
  `tanggal_mulai` date DEFAULT NULL,
  `tanggal_selesai` date DEFAULT NULL,
  PRIMARY KEY (`id_promo`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.promo: ~2 rows (approximately)
INSERT INTO `promo` (`id_promo`, `nama_promo`, `diskon`, `tanggal_mulai`, `tanggal_selesai`) VALUES
	('PRO001', 'Promo Idul Adha Diskon 10%', 10.00, '2026-05-24', '2026-05-30'),
	('PRO002', 'Diskon 15% ', 15.00, '2026-06-01', '2026-06-30');

-- Dumping structure for table db_laundry.status_pesanan
CREATE TABLE IF NOT EXISTS `status_pesanan` (
  `id_status` char(6) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `nama_status` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  PRIMARY KEY (`id_status`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Dumping data for table db_laundry.status_pesanan: ~6 rows (approximately)
INSERT INTO `status_pesanan` (`id_status`, `nama_status`) VALUES
	('STS001', 'Menunggu'),
	('STS002', 'Diproses'),
	('STS003', 'Dicuci'),
	('STS004', 'Disetrika'),
	('STS005', 'Selesai'),
	('STS006', 'Sudah Diambil');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
