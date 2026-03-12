const flagshipProjects = [
  {
    name: "SmartVault",
    label: "AI-powered file management",
    description:
      "Built for real usage with secure storage, AI-assisted file discovery, and full-stack architecture on Next.js and Appwrite.",
    impact: "1000+ users, 50% faster file search",
    stack: ["Next.js 15", "TypeScript", "Appwrite", "Tailwind", "Google Gemini"],
    repo: "https://github.com/himaenshuu/smartVault",
    live: "https://smart-vault-ecru.vercel.app/",
    caseStudy: "./case-studies/smartvault.html",
  },
  {
    name: "ShopSense",
    label: "Conversational commerce assistant",
    description:
      "Converted traditional online shopping flow into a chat-first product discovery and recommendation experience.",
    impact: "Shopping moved from browse-first to chat-first interactions",
    stack: ["Next.js", "TypeScript", "MongoDB", "Gemini", "SendGrid"],
    repo: "https://github.com/himaenshuu/ShopSense",
    live: "",
    caseStudy: "./case-studies/shopsense.html",
  },
  {
    name: "Multimodal RAG Application",
    label: "Retrieval platform for diverse content",
    description:
      "Question answering over PDFs, web pages, papers, audio, and video using RAG with semantic retrieval and Gemini response generation.",
    impact: "Unified ingestion and retrieval across 5 content types",
    stack: ["Python", "FastAPI", "Streamlit", "Qdrant", "Gemini"],
    repo: "https://github.com/himaenshuu/Multi_modal_rag-application",
    live: "",
    caseStudy: "./case-studies/multimodal-rag.html",
  },
];

function createProjectCard(project) {
  const article = document.createElement("article");
  article.className = "project-card";

  const top = document.createElement("div");
  top.className = "project-top";
  const titleWrap = document.createElement("div");

  const meta = document.createElement("p");
  meta.className = "project-meta";
  meta.textContent = project.label;

  const title = document.createElement("h3");
  title.textContent = project.name;

  titleWrap.append(meta, title);
  top.appendChild(titleWrap);

  const desc = document.createElement("p");
  desc.textContent = project.description;

  const impact = document.createElement("p");
  impact.className = "project-meta";
  impact.textContent = `Impact: ${project.impact}`;

  const tags = document.createElement("div");
  tags.className = "project-tags";
  project.stack.forEach((tag) => {
    const chip = document.createElement("span");
    chip.textContent = tag;
    tags.appendChild(chip);
  });

  const links = document.createElement("div");
  links.className = "project-links";

  const caseLink = document.createElement("a");
  caseLink.href = project.caseStudy;
  caseLink.textContent = "Case study";
  links.appendChild(caseLink);

  const repoLink = document.createElement("a");
  repoLink.href = project.repo;
  repoLink.target = "_blank";
  repoLink.rel = "noreferrer";
  repoLink.textContent = "Repository";
  links.appendChild(repoLink);

  if (project.live) {
    const liveLink = document.createElement("a");
    liveLink.href = project.live;
    liveLink.target = "_blank";
    liveLink.rel = "noreferrer";
    liveLink.textContent = "Live demo";
    links.appendChild(liveLink);
  }

  article.append(top, desc, impact, tags, links);
  return article;
}

const projectGrid = document.getElementById("project-grid");

if (projectGrid) {
  flagshipProjects.forEach((project) => {
    projectGrid.appendChild(createProjectCard(project));
  });
}
