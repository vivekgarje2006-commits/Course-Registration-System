<!doctype html>
<html lang="en">
<head>
    <link rel="stylesheet" href="style.css">
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Upload a document | UReminder</title>
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=DM+Sans:wght@400;500;600;700&family=Manrope:wght@500;600;700;800&display=swap" rel="stylesheet">
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <aside class="sidebar" id="app-sidebar">
    <a class="brand" href="index.html">
      <span class="brand-icon">U</span>
      <span>UReminder</span>
    </a>

    <p class="nav-heading">WORKSPACE</p>
    <nav class="nav-list" aria-label="Main navigation">
      <a class="nav-link" href="index.html">
        <span class="nav-icon">
          <svg viewBox="0 0 24 24" aria-hidden="true">
            <rect x="3.5" y="3.5" width="7" height="7" rx="1.5"/>
            <rect x="13.5" y="3.5" width="7" height="7" rx="1.5"/>
            <rect x="3.5" y="13.5" width="7" height="7" rx="1.5"/>
            <rect x="13.5" y="13.5" width="7" height="7" rx="1.5"/>
          </svg>
        </span>
        Dashboard
      </a>

      <a class="nav-link" href="documents.html">
        <span class="nav-icon">
          <svg viewBox="0 0 24 24" aria-hidden="true">
            <path d="M13.5 3.5h-7a2 2 0 0 0-2 2v13a2 2 0 0 0 2 2h11a2 2 0 0 0 2-2V9.5z"/>
            <path d="M13.5 3.5v6h6M8 14h8m-8 4h8"/>
          </svg>
        </span>
        Documents
      </a>

      <a class="nav-link" href="index.html#reminders">
        <span class="nav-icon">
          <svg viewBox="0 0 24 24" aria-hidden="true">
            <circle cx="12" cy="13" r="8.5"/>
            <path d="M12 8v5l3.2 2M9 3.5h6"/>
          </svg>
        </span>
        Reminders
        <span class="nav-badge">5</span>
      </a>

      <a class="nav-link" href="index.html#notifications">
        <span class="nav-icon">
          <svg viewBox="0 0 24 24" aria-hidden="true">
            <path d="M18 9a6 6 0 0 0-12 0c0 7-3 7-3 9h18c0-2-3-2-3-9m-8 12a2 2 0 0 0 4 0"/>
          </svg>
        </span>
        Notifications
        <span class="notice-dot"></span>
      </a>
    </nav>

    <p class="nav-heading preferences">PREFERENCES</p>
    <nav class="nav-list" aria-label="Preferences">
      <a class="nav-link" href="index.html#settings">
        <span class="nav-icon">
          <svg viewBox="0 0 24 24" aria-hidden="true">
            <circle cx="12" cy="12" r="3"/>
            <path d="m19.4 15 .1.1 1.1.9-1.2 2.1-1.4-.5a8 8 0 0 1-1.5.9l-.3 1.5h-2.4l-.3-1.5a8 8 0 0 1-1.5-.9l-1.4.5-1.2-2.1 1.1-.9a7 7 0 0 1 0-1.8l-1.1-.9 1.2-2.1 1.4.5a8 8 0 0 1 1.5-.9l.3-1.5h2.4l.3 1.5a8 8 0 0 1 1.5.9l1.4-.5 1.2 2.1-1.1.9a7 7 0 0 1 0 1.8Z"/>
          </svg>
        </span>
        Settings
      </a>
    </nav>

    <div class="sidebar-bottom">
      <div class="help-box">
        <strong>Need a hand?</strong>
        <p>We're here to help you stay on track.</p>
        <a href="mailto:hello@ureminder.app">Visit help center →</a>
      </div>
      <div class="user-card">
        <span class="avatar">V</span>
        <span>
          <strong>Vivek Sharma</strong>
          <small>Personal account</small>
        </span>
      </div>
    </div>
  </aside>

  <main class="main-content">
    <header class="topbar">
      <button
        class="sidebar-toggle-button"
        id="sidebar-toggle"
        type="button"
        aria-expanded="true"
        aria-controls="app-sidebar"
        aria-label="Hide sidebar"
        title="Hide or show sidebar">☰</button>

      <div class="breadcrumb">
        <a href="index.html">Workspace</a>
        <span>/</span>
        <strong>Upload document</strong>
      </div>
      <a class="user-avatar" href="index.html" aria-label="Back to dashboard">V</a>
    </header>

    <div class="page-content upload-page">
      <a class="back-link" href="index.html">← Back to dashboard</a>
      <p class="eyebrow">YOUR DOCUMENTS</p>
      <h1>Upload a document</h1>
      <p class="subheading">Keep the important dates in your life from catching you by surprise.</p>

      <section class="upload-card" aria-labelledby="upload-heading">
        <div class="upload-card-heading">
          <span class="document-icon">▤</span>
          <div>
            <h2 id="upload-heading">Add a new document</h2>
            <p>Choose a file from your device to get started.</p>
          </div>
        </div>

        <label class="drop-area" for="document-file">
          <span class="upload-symbol">↑</span>
          <strong>Choose a document from your device</strong>
          <span>PDF, JPG, or PNG · Up to 10 MB</span>
          <input id="document-file" type="file" accept=".pdf,.jpg,.jpeg,.png,application/pdf,image/jpeg,image/png">
        </label>

        <p class="privacy-note">
          Your file chooser opens on this device. This prototype does not upload, analyze, or save the file.
        </p>
        <button class="button analyze-button" type="button" disabled>
          Analyze document <span>Coming soon</span>
        </button>
      </section>

      <aside class="next-step">
        <strong>What happens next?</strong>
        <p>Document analysis can be added later to find important dates and create reminders.</p>
      </aside>

      <footer class="footer">
        <span>© 2026 UReminder</span>
        <span>Small reminders. More peace of mind.</span>
        <a href="mailto:hello@ureminder.app">Help &amp; support</a>
      </footer>
    </div>
  </main>

  <script>
    const sidebarToggle = document.getElementById("sidebar-toggle");
    sidebarToggle.addEventListener("click", () => {
      const isHidden = document.body.classList.toggle("sidebar-hidden");
      sidebarToggle.setAttribute("aria-expanded", String(!isHidden));
      sidebarToggle.setAttribute("aria-label", isHidden ? "Show sidebar" : "Hide sidebar");
    });
  </script>
</body>
</html>
