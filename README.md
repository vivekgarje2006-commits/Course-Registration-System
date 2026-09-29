:root {
    --ink: #202338;
    --muted: #85899b;
    --line: #eceef4;
    --purple: #6555e8;
    --bg: #f7f8fc;
    --font: "DM Sans", sans-serif;
    --display: "Manrope", sans-serif;
}

* {
    box-sizing: border-box;
}

html {
    scroll-behavior: smooth;
}

body {
    margin: 0;
    background: var(--bg);
    color: var(--ink);
    font: 14px var(--font);
    -webkit-font-smoothing: antialiased;
}

a {
    color: inherit;
}

.sidebar {
    position: fixed;
    inset: 0 auto 0 0;
    width: 250px;
    padding: 28px 18px 16px;
    background: #fff;
    border-right: 1px solid var(--line);
    display: flex;
    flex-direction: column;
    z-index: 2;
}

.brand {
    display: flex;
    align-items: center;
    gap: 10px;
    margin: 0 0 44px 8px;
    text-decoration: none;
    font: 800 19px var(--display);
    letter-spacing: -.6px;
}

.brand-icon {
    display: grid;
    place-items: center;
    width: 34px;
    height: 34px;
    border-radius: 11px;
    background: #efedff;
    color: var(--purple);
    font-size: 18px;
}

.nav-heading {
    margin: 0 0 10px 12px;
    color: #a0a3b0;
    font-size: 10px;
    font-weight: 700;
    letter-spacing: 1.2px;
}

.nav-list {
    display: grid;
    gap: 5px;
}

.nav-link {
    position: relative;
    display: flex;
    align-items: center;
    gap: 12px;
    min-height: 44px;
    padding: 0 12px;
    border-radius: 9px;
    color: #777b8d;
    text-decoration: none;
    font-weight: 600;
}

.nav-link:hover {
    background: #f7f6ff;
    color: var(--purple);
}

.nav-link.active {
    background: #f0eeff;
    color: #5d4dd9;
}

.nav-icon {
    display: inline-grid;
    place-items: center;
    width: 19px;
    font-size: 19px;
}

.nav-badge {
    margin-left: auto;
    display: grid;
    place-items: center;
    width: 22px;
    height: 22px;
    border-radius: 7px;
    background: #fff;
    color: var(--purple);
    font-size: 11px;
}

.notice-dot {
    margin-left: auto;
    width: 7px;
    height: 7px;
    border-radius: 50%;
    background: #ef8288;
}

.preferences {
    margin-top: 32px;
}

.sidebar-bottom {
    margin-top: auto;
}

.help-box {
    margin: 0 3px 18px;
    padding: 15px;
    border: 1px solid #eeebff;
    border-radius: 12px;
    background: #f8f7ff;
}

.help-box strong,
.user-card strong {
    font-size: 12px;
}

.help-box p {
    margin: 6px 0 10px;
    color: #898c9c;
    font-size: 11px;
    line-height: 1.5;
}

.help-box a {
    color: #6152db;
    text-decoration: none;
    font-size: 11px;
    font-weight: 700;
}

.user-card {
    display: flex;
    align-items: center;
    gap: 10px;
    padding: 13px 4px 0;
    border-top: 1px solid var(--line);
}

.avatar,
.user-avatar {
    display: grid;
    place-items: center;
    width: 34px;
    height: 34px;
    border: 0;
    border-radius: 50%;
    background: #ede8df;
    color: #62564a;
    font-weight: 700;
    text-decoration: none;
}

.user-card small {
    display: block;
    margin-top: 3px;
    color: #999bab;
    font-size: 10px;
}

.main-content {
    min-height: 100vh;
    margin-left: 250px;
}

.topbar {
    position: sticky;
    top: 0;
    z-index: 1;
    height: 66px;
    padding: 0 48px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    background: #fff;
    border-bottom: 1px solid var(--line);
}

.breadcrumb {
    color: #999cab;
    font-size: 12px;
}

.breadcrumb a {
    text-decoration: none;
}

.breadcrumb span {
    margin: 0 9px;
    color: #c3c5cf;
}

.breadcrumb strong {
    color: #52566a;
    font-weight: 600;
}

.user-avatar {
    width: 31px;
    height: 31px;
    font-size: 11px;
}

.page-content {
    max-width: 1150px;
    margin: 0 auto;
    padding: 42px 48px 25px;
}

.welcome-row {
    display: flex;
    align-items: flex-end;
    justify-content: space-between;
    gap: 20px;
    margin-bottom: 27px;
}

.eyebrow {
    margin: 0 0 10px;
    color: #989bab;
    font-size: 10px;
    font-weight: 700;
    letter-spacing: 1.2px;
}

h1,
h2,
p {
    margin-top: 0;
}

h1 {
    margin-bottom: 7px;
    font: 700 28px/1.25 var(--display);
    letter-spacing: -1px;
}

.sun {
    color: #efbd68;
    font-size: 19px;
}

.subheading {
    margin-bottom: 0;
    color: #898c9d;
    font-size: 13px;
    line-height: 1.6;
}

.button {
    min-height: 42px;
    padding: 0 16px;
    display: inline-flex;
    align-items: center;
    justify-content: center;
    gap: 8px;
    border: 0;
    border-radius: 9px;
    text-decoration: none;
    font: 700 12px var(--font);
    cursor: pointer;
}

.primary-button {
    background: var(--purple);
    color: #fff;
    box-shadow: 0 5px 13px #6656e829;
}

.primary-button:hover {
    background: #5544d4;
}

.primary-button span {
    font-size: 18px;
    font-weight: 400;
}

.stats-grid {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 15px;
}

.stat-card {
    min-height: 140px;
    padding: 17px;
    display: flex;
    flex-direction: column;
    align-items: flex-start;
    background: #fff;
    border: 1px solid var(--line);
    border-radius: 12px;
}

.stat-top {
    width: 100%;
    display: flex;
    align-items: center;
    justify-content: space-between;
    color: #777b8e;
    font-size: 11px;
    font-weight: 600;
}

.stat-icon {
    width: 31px;
    height: 31px;
    display: grid;
    place-items: center;
    border-radius: 10px;
    font-size: 18px;
}

.stat-icon.purple {
    background: #f0eeff;
    color: #6b5be7;
}

.stat-icon.coral {
    background: #fff0ef;
    color: #df777a;
}

.stat-icon.blue {
    background: #edf5ff;
    color: #5591d9;
}

.stat-number {
    margin: 7px 0 8px;
    font: 700 29px/1 var(--display);
    letter-spacing: -1px;
}

.stat-note {
    font-size: 10px;
    font-weight: 600;
}

.purple-text {
    color: #7668d7;
}

.coral-text {
    color: #d87677;
}

.green-text {
    color: #58a181;
}

.reminders-section {
    margin-top: 35px;
}

.section-heading {
    display: flex;
    align-items: flex-end;
    justify-content: space-between;
    gap: 12px;
    margin-bottom: 14px;
}

.section-heading h2 {
    margin: 0;
    font: 700 17px var(--display);
    letter-spacing: -.3px;
}

.section-heading p {
    margin: 5px 0 0;
    color: #9699a8;
    font-size: 11px;
}

.count {
    margin-left: 5px;
    padding: 3px 7px;
    border-radius: 6 zpx;
    background: #efedff;
    color: #6859df;
    font: 700 10px var(--font);
    vertical-align: 2px;
}

.view-link,
.list-footer a {
    color: #6354dc;
    text-decoration: none;
    font-size: 11px;
    font-weight: 700;
}

.reminder-list {
    overflow: hidden;
    background: #fff;
    border: 1px solid var(--line);
    border-radius: 12px;
}

.reminder-row {
    min-height: 65px;
    padding: 0 16px;
    display: grid;
    grid-template-columns: 36px minmax(0, 1fr) 100px 80px;
    align-items: center;
    gap: 12px;
    border-bottom: 1px solid #f0f1f5;
}

.reminder-row:last-child {
    border-bottom: 0;
}

.reminder-icon {
    width: 33px;
    height: 33px;
    display: grid;
    place-items: center;
    border-radius: 10px;
    font-size: 20px;
}

.lavender {
    background: #f0eeff;
    color: #7160df;
}

.mint {
    background: #eaf7f5;
    color: #4ca999;
}

.peach {
    background: #fff5e9;
    color: #dc9a52;
}

.sky {
    background: #edf4ff;
    color: #5488d1;
}

.reminder-name,
.reminder-date {
    display: grid;
    gap: 5px;
    min-width: 0;
}

.reminder-name strong,
.reminder-date strong {
    overflow: hidden;
    color: #34374b;
    font-size: 11px;
    text-overflow: ellipsis;
    white-space: nowrap;
}

.reminder-name small,
.reminder-date small {
    overflow: hidden;
    color: #9699a8;
    font-size: 10px;
    text-overflow: ellipsis;
    white-space: nowrap;
}

.tag {
    justify-self: start;
    padding: 5px 8px;
    border-radius: 6px;
    background: #f5f5f9;
    color: #888b9a;
    font-size: 9px;
    white-space: nowrap;
}

.tag.soon {
    background: #fff2ec;
    color: #d98a68;
}

.list-footer {
    min-height: 38px;
    padding: 0 3px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    color: #9a9cab;
    font-size: 10px;
}

.list-footer>span {
    color: #70a98f;
}

.upload-banner {
    position: relative;
    min-height: 180px;
    margin-top: 21px;
    padding: 23px 30px;
    overflow: hidden;
    display: flex;
    align-items: center;
    border-radius: 14px;
    background: linear-gradient(110deg, #5d4cdb, #8172ec);
    color: #fff;
}

.banner-eyebrow {
    color: #d2ceff;
    font-size: 9px;
    font-weight: 700;
    letter-spacing: 1.3px;
}

.upload-banner h2 {
    margin: 7px 0 5px;
    font: 700 20px/1.35 var(--display);
}

.upload-banner p {
    margin-bottom: 13px;
    color: #e1ddff;
    font-size: 10px;
}

.white-button {
    min-height: 34px;
    padding: 0 12px;
    background: #fff;
    color: #5c4dd2;
    font-size: 10px;
}

.white-button>span {
    margin-left: 5px;
    font-size: 14px;
}

.banner-art {
    position: absolute;
    right: 12%;
    top: 50%;
    width: 75px;
    height: 92px;
    display: grid;
    place-items: center;
    transform: translateY(-50%) rotate(-7deg);
    border: 1px solid #ffffff88;
    border-radius: 9px;
    background: #ffffffdb;
    color: #8b7fea;
    font-size: 42px;
    box-shadow: 0 12px 30px #3225a34a;
}

.banner-art span {
    position: absolute;
    right: -9px;
    bottom: 7px;
    width: 23px;
    height: 23px;
    display: grid;
    place-items: center;
    border: 3px solid #e1ddff;
    border-radius: 50%;
    background: #66c4a3;
    color: #fff;
    font-size: 12px;
}

.footer {
    padding: 19px 1px 0;
    display: flex;
    justify-content: space-between;
    gap: 10px;
    color: #a4a6b2;
    font-size: 9px;
}

.footer a {
    color: #85889a;
    text-decoration: none;
}

/* Upload page */
.upload-page {
    max-width: 900px;
}

.back-link {
    display: inline-block;
    margin-bottom: 28px;
    color: #777b8d;
    text-decoration: none;
    font-size: 11px;
    font-weight: 600;
}

.back-link:hover {
    color: var(--purple);
}

.upload-page h1 {
    margin-top: 0;
}

.upload-card {
    max-width: 700px;
    margin: 28px auto 0;
    padding: 25px;
    background: #fff;
    border: 1px solid var(--line);
    border-radius: 14px;
    box-shadow: 0 4px 18px #252a4007;
}

.upload-card-heading {
    display: flex;
    align-items: center;
    gap: 12px;
    margin-bottom: 20px;
}

.document-icon {
    width: 40px;
    height: 40px;
    display: grid;
    place-items: center;
    border-radius: 11px;
    background: #f0eeff;
    color: #6858e4;
    font-size: 22px;
}

.upload-card-heading h2 {
    margin: 0 0 5px;
    font: 700 15px var(--display);
}

.upload-card-heading p {
    margin: 0;
    color: #9295a5;
    font-size: 11px;
}

.drop-area {
    min-height: 235px;
    padding: 22px;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    gap: 11px;
    border: 1.5px dashed #d9d6ef;
    border-radius: 12px;
    background: #fcfbff;
    cursor: pointer;
    text-align: center;
}

.drop-area:hover,
.drop-area:focus-within {
    border-color: #8b7fea;
    background: #f9f8ff;
}

.upload-symbol {
    width: 42px;
    height: 42px;
    display: grid;
    place-items: center;
    border-radius: 13px;
    background: #efedff;
    color: #6959e5;
    font-size: 25px;
}

.drop-area strong {
    font: 700 13px var(--display);
}

.drop-area>span:last-of-type {
    color: #989baa;
    font-size: 10px;
}

.drop-area input {
    max-width: 230px;
    color: #777b8d;
    font: 11px var(--font);
}

.privacy-note {
    margin: 14px 0 18px;
    color: #9093a2;
    font-size: 10px;
    line-height: 1.5;
}

.analyze-button {
    width: 100%;
    background: #efeff4;
    color: #aaaebb;
    cursor: not-allowed;
}

.analyze-button span {
    margin-left: 3px;
    font-size: 9px;
    font-weight: 500;
}

.next-step {
    max-width: 700px;
    margin: 16px auto 0;
    padding: 14px 16px;
    border: 1px solid #eeebff;
    border-radius: 10px;
    background: #f8f7ff;
}

.next-step strong {
    font-size: 11px;
}

.next-step p {
    margin: 5px 0 0;
    color: #85889a;
    font-size: 10px;
    line-height: 1.6;
}

.upload-page .footer {
    max-width: 700px;
    margin: auto;
    padding-top: 24px;
}

/* Documents page */
.documents-heading {
    display: flex;
    align-items: flex-end;
    justify-content: space-between;
    gap: 20px;
    margin-bottom: 25px;
}

.documents-heading h1 {
    margin-bottom: 7px;
}

.document-summary {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 14px;
    margin-bottom: 29px;
}

.document-summary>div {
    min-height: 77px;
    padding: 15px 17px;
    display: flex;
    align-items: center;
    gap: 10px;
    background: #fff;
    border: 1px solid var(--line);
    border-radius: 11px;
}

.document-summary strong {
    font: 700 21px var(--display);
}

.document-summary>div>span:last-child {
    color: #85899b;
    font-size: 11px;
}

.summary-dot {
    width: 8px;
    height: 8px;
    border-radius: 50%;
}

.purple-dot {
    background: #7668e8;
}

.green-dot {
    background: #65b391;
}

.amber-dot {
    background: #e6ae64;
}

.documents-library {
    background: #fff;
    border: 1px solid var(--line);
    border-radius: 12px;
    overflow: hidden;
}

.library-toolbar {
    min-height: 80px;
    padding: 16px 18px;
    display: flex;
    align-items: center;
    justify-content: space-between;
    gap: 16px;
    border-bottom: 1px solid #f0f1f5;
}

.library-toolbar h2 {
    margin: 0;
    font: 700 16px var(--display);
}

.library-toolbar p {
    margin: 5px 0 0;
    color: #9699a8;
    font-size: 11px;
}

.search-box {
    width: 210px;
    height: 36px;
    padding: 0 10px;
    display: flex;
    align-items: center;
    gap: 8px;
    border: 1px solid #e9eaf0;
    border-radius: 8px;
    color: #999cab;
}

.search-box>span {
    font-size: 20px;
}

.search-box input {
    width: 100%;
    min-width: 0;
    border: 0;
    outline: 0;
    color: var(--ink);
    font: 11px var(--font);
    background: transparent;
}

.search-box input::placeholder {
    color: #a0a3b0;
}

.document-row {
    min-height: 74px;
    padding: 10px 17px;
    display: grid;
    grid-template-columns: 36px minmax(140px, 1fr) 105px 105px 88px 14px;
    align-items: center;
    gap: 12px;
    border-bottom: 1px solid #f0f1f5;
}

.document-row:last-child {
    border-bottom: 0;
}

.document-type-icon {
    width: 33px;
    height: 33px;
    display: grid;
    place-items: center;
    border-radius: 10px;
    font-size: 20px;
}

.type-insurance {
    background: #f0eeff;
    color: #7160df;
}

.type-vehicle {
    background: #eaf7f5;
    color: #4ca999;
}

.type-subscription {
    background: #fff5e9;
    color: #dc9a52;
}

.type-identity {
    background: #edf4ff;
    color: #5488d1;
}

.document-details,
.document-expiry {
    min-width: 0;
    display: grid;
    gap: 5px;
}

.document-details strong,
.document-expiry strong {
    overflow: hidden;
    color: #34374b;
    font-size: 11px;
    text-overflow: ellipsis;
    white-space: nowrap;
}

.document-details small,
.document-expiry small {
    overflow: hidden;
    color: #9699a8;
    font-size: 9px;
    text-overflow: ellipsis;
    white-space: nowrap;
}

.document-category {
    color: #818596;
    font-size: 10px;
}

.document-status {
    justify-self: start;
    padding: 5px 8px;
    border-radius: 6px;
    font-size: 9px;
    white-space: nowrap;
}

.status-soon {
    background: #fff2ec;
    color: #d98a68;
}

.status-good {
    background: #edf8f2;
    color: #58a181;
}

.document-more {
    color: #a9acb8;
    font-size: 22px;
    text-align: right;
}

.documents-footnote {
    padding: 12px 17px;
    border-top: 1px solid #f0f1f5;
    color: #999cab;
    font-size: 10px;
}

@media (max-width: 1000px) {
    .sidebar {
        width: 220px;
    }

    .main-content {
        margin-left: 220px;
    }

    .topbar {
        padding: 0 30px;
    }

    .page-content {
        padding: 34px 30px 24px;
    }

    .stat-card {
        padding: 14px;
    }

    .reminder-row {
        grid-template-columns: 34px minmax(0, 1fr) 92px 70px;
        gap: 8px;
    }

    .document-row {
        grid-template-columns: 34px minmax(130px, 1fr) 88px 92px 14px;
        gap: 9px;
    }

    .document-category {
        display: none;
    }
}

@media (max-width: 720px) {
    .sidebar {
        width: 65px;
        padding: 22px 8px 12px;
        align-items: center;
    }

    .brand {
        margin: 0 0 38px;
    }

    .brand>span:last-child,
    .nav-heading,
    .nav-link:not(.active) {
        font-size: 0;
    }

    .nav-link {
        width: 47px;
        justify-content: center;
        padding: 0;
        font-size: 0 !important;
    }

    .nav-icon {
        font-size: 19px;
    }

    .nav-link.active {
        font-size: 0;
    }

    .nav-badge {
        position: absolute;
        top: 1px;
        right: 0;
        width: 15px;
        height: 15px;
        border-radius: 50%;
        background: var(--purple);
        color: #fff;
        font-size: 8px;
    }

    .notice-dot {
        position: absolute;
        top: 9px;
        right: 9px;
    }

    .preferences {
        display: none;
    }

    .help-box,
    .user-card>span:not(.avatar) {
        display: none;
    }

    .user-card {
        border: 0;
        padding: 0;
    }

    .avatar {
        width: 32px;
        height: 32px;
    }

    .main-content {
        margin-left: 65px;
    }

    .topbar {
        height: 58px;
        padding: 0 20px;
    }

    .page-content {
        padding: 29px 20px 22px;
    }

    .welcome-row {
        align-items: flex-start;
    }

    h1 {
        font-size: 24px;
    }

    .stats-grid {
        gap: 9px;
    }

    .stat-card {
        min-height: 130px;
        padding: 12px;
    }

    .stat-top {
        font-size: 10px;
    }

    .stat-note {
        font-size: 8px;
    }

    .reminder-row {
        grid-template-columns: 33px minmax(0, 1fr) 85px;
    }

    .document-row {
        grid-template-columns: 33px minmax(0, 1fr) 83px 14px;
        gap: 8px;
        padding: 10px;
    }

    .document-status {
        display: none;
    }

    .document-summary {
        gap: 8px;
    }

    .document-summary>div {
        padding: 12px;
        gap: 7px;
    }

    .document-summary>div>span:last-child {
        font-size: 9px;
    }

    .tag {
        display: none;
    }

    .banner-art {
        right: 7%;
        opacity: .7;
    }
}

@media (max-width: 500px) {
    .topbar {
        padding: 0 14px;
    }

    .page-content {
        padding: 24px 14px 20px;
    }

    .welcome-row {
        display: block;
    }

    .primary-button {
        margin-top: 16px;
    }

    .stats-grid {
        grid-template-columns: 1fr;
    }

    .stat-card {
        min-height: auto;
        display: grid;
        grid-template-columns: 1fr auto;
    }

    .stat-top {
        display: contents;
    }

    .stat-top>span:first-child {
        grid-column: 1;
    }

    .stat-icon {
        grid-column: 2;
        grid-row: 1 / 3;
    }

    .stat-number {
        margin: 5px 0 8px;
    }

    .stat-note {
        grid-column: 1 / 3;
    }

    .section-heading h2 {
        font-size: 15px;
    }

    .view-link {
        font-size: 9px;
    }

    .reminder-row {
        grid-template-columns: 30px minmax(0, 1fr) 76px;
        gap: 7px;
        padding: 0 9px;
    }

    .reminder-name strong,
    .reminder-date strong {
        font-size: 9px;
    }

    .reminder-name small,
    .reminder-date small {
        font-size: 8px;
    }

    .list-footer {
        font-size: 8px;
    }

    .list-footer a {
        font-size: 9px;
    }

    .upload-banner {
        min-height: 190px;
        padding: 20px;
    }

    .upload-banner h2 {
        font-size: 17px;
    }

    .banner-art {
        right: 4%;
        transform: translateY(-50%) scale(.8) rotate(-7deg);
        opacity: .4;
    }

    .footer span:nth-child(2) {
        display: none;
    }

    .upload-card {
        padding: 16px;
    }

    .drop-area {
        min-height: 210px;
    }

    .documents-heading {
        display: block;
    }

    .documents-heading .button {
        margin-top: 16px;
    }

    .document-summary {
        grid-template-columns: 1fr;
        gap: 7px;
    }

    .document-summary>div {
        min-height: 54px;
    }

    .library-toolbar {
        align-items: flex-start;
        flex-direction: column;
        padding: 14px;
    }

    .search-box {
        width: 100%;
    }

    .document-row {
        grid-template-columns: 31px minmax(0, 1fr) 80px 12px;
        padding: 10px 8px;
        gap: 6px;
    }

    .document-expiry strong {
        font-size: 9px;
    }

    .document-expiry small,
    .document-details small {
        font-size: 8px;
    }
}

@media (prefers-reduced-motion: reduce) {
    html {
        scroll-behavior: auto;
    }
}

/* Teal and white palette */
:root {
    --ink: #24343a;
    --muted: #77878a;
    --line: #e5edeb;
    --purple: #16796f;
    --bg: #f6faf9;
}

.brand-icon,
.nav-link.active,
.stat-icon.purple,
.lavender,
.count,
.document-icon,
.type-insurance,
.search-box:focus-within {
    background-color: #e8f5f2;
    color: #16796f;
}

.nav-link:hover,
.back-link:hover,
.help-box a,
.view-link,
.list-footer a {
    color: #16796f;
}

.nav-badge {
    color: #16796f;
}

.help-box,
.next-step {
    border-color: #dceeea;
    background: #f2f9f7;
}

.primary-button {
    background: #16796f;
    box-shadow: 0 5px 13px #16796f29;
}

.primary-button:hover {
    background: #11665e;
}

.purple-text,
.stat-icon.purple,
.purple-dot {
    color: #16796f;
}

.purple-dot {
    background: #16796f;
}

.upload-banner {
    background: linear-gradient(110deg, #126f66, #23988a);
}

.upload-banner .banner-eyebrow {
    color: #d3f0ea;
}

.upload-banner p {
    color: #e0f4f0;
}

.white-button {
    color: #126f66;
}

.banner-art {
    color: #388f83;
}

.drop-area {
    border-color: #c8e4df;
    background: #fbfdfc;
}

.drop-area:hover,
.drop-area:focus-within {
    border-color: #63aa9e;
    background: #f2faf8;
}

.upload-symbol {
    background: #e8f5f2;
    color: #16796f;
}

.type-insurance {
    background: #e8f5f2;
    color: #16796f;
}

/* Direct click toggle for the sidebar */
.sidebar-toggle-button {
    appearance: none;
    font-family: inherit;
}

body.sidebar-hidden .sidebar {
    transform: translateX(-100%);
    visibility: hidden;
}

body.sidebar-hidden .main-content {
    margin-left: 0;
}
.nav-icon svg {
  display: block;
  width: 18px;
  height: 18px;
  fill: none;
  stroke: currentColor;
  stroke-width: 1.7;
  stroke-linecap: round;
  stroke-linejoin: round;
}
